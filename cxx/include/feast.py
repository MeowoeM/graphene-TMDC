import os
import sys
import numpy as np
import scipy.sparse as sp
import ctypes
from numpy import ctypeslib

mkl_lib = ctypes.cdll.LoadLibrary('/opt/intel/compilers_and_libraries_2019.0.117/mac/mkl/lib/libmkl_rt.dylib')

def feastinit():
	fpm = np.zeros(128, dtype=np.int, order='C')

	# Specifies whether Extended Eigensolver routines print runtime status.

	# fpm[0]=0
	# Extended Eigensolver routines do not generate runtime messages at all.

	# fpm[0]=1
	# Extended Eigensolver routines print runtime status to the screen.
	fpm[0] = 0

	# The number of contour points Ne = 8 (see the description of FEAST algorithm). Must be one of {3,4,5,6,8,10,12,16,20,24,32,40,48}.
	fpm[1] = 8

	# Error trace double precision stopping criteria ε (ε = 10e-fpm[2]).
	fpm[2] = 12

	# Maximum number of Extended Eigensolver refinement loops allowed. If no convergence is reached within fpm[3] refinement loops, Extended Eigensolver routines return info=2.Pattern
	fpm[3] = 20

	# User initial subspace. If fpm[4]=0 then Extended Eigensolver routines generate initial subspace, if fpm[4]=1 the user supplied initial subspace is used.
	fpm[4] = 0

	# Extended Eigensolver stopping test.
	fpm[5] = 0

	# Error trace single precision stopping criteria (10e-fpm[6]).
	fpm[6] = 5

	# fpm[13]=0
	# Standard use for Extended Eigensolver routines.

	# fpm[13]=1
	# Non-standard use for Extended Eigensolver routines: return the computed eigenvectors subspace after one single contour integration.
	fpm[13] = 0

	# Specifies whether Extended Eigensolver routines check input matrices (applies to CSR format only).

	# fpm[26]=0
	# Extended Eigensolver routines do not check input matrices.

	# fpm[26]=1
	# Extended Eigensolver routines check input matrices.
	fpm[26] = 0

	# Use the Intel MKL PARDISO solver with the user-defined PARDISO iparm array settings.

	# NOTE
	# This option can only be used by Extended Eigensolver Predefined Interfaces for Sparse Matrices.

	# fpm[63]=0
	# Extended Eigensolver routines use the Intel MKL PARDISO default iparm settings defined by calling the pardisoinit subroutine.

	# fpm[63]=1
	# The values from fpm[64] to fpm[127] correspond to iparm[0] to iparm[63] respectively according to the formula fpm[64 + i]= iparm[i] for i = 0, 1, ..., 63.
	fpm[63] = 0

	return fpm

def feast(uplo, A, m0, emin, emax):
	if isinstance(uplo, str):
		c_uplo = uplo.encode('utf-8')
	else:
		print('uplo must be one char')
	
	n = A.shape[0]

	a = A.data.ctypes.data_as(ctypeslib.ndpointer(np.complex128, ndim=1, flags='C'))
	iaa = A.indptr + 1
	jaa = A.indices + 1
	ia = iaa.ctypes.data_as(ctypeslib.ndpointer(ctypes.c_int, ndim=1, flags='C'))
	# print('a', (A.indptr + 1))
	ja = jaa.ctypes.data_as(ctypeslib.ndpointer(ctypes.c_int, ndim=1, flags='C'))

	# print(A.data, n, A.indptr, A.indices)

	fpm =np.zeros(128, dtype=np.int32, order='C')
	e = np.empty(m0, dtype=np.float64, order='C')
	v = np.empty((n, m0), dtype=np.complex, order='C')
	res = np.empty(m0, dtype=np.complex, order='C')

	c_fpm = fpm.ctypes.data_as(ctypeslib.ndpointer(np.int32, ndim=1, flags='C'))
	c_e = e.ctypes.data_as(ctypeslib.ndpointer(np.float64, ndim=1, flags='C'))
	c_v = v.ctypes.data_as(ctypeslib.ndpointer(np.complex128, ndim=2, flags='C'))
	c_res = res.ctypes.data_as(ctypeslib.ndpointer(np.complex128, ndim=2, flags='C'))

	espout = ctypes.c_double(0)
	loop = ctypes.c_int(0)
	c_emin = ctypes.c_double(emin)
	c_emax = ctypes.c_double(emax)
	c_m0 = ctypes.c_int(m0)
	m = ctypes.c_int(0)
	info = ctypes.c_int(0)

	# feast init
	mkl_lib.feastinit(c_fpm)
	fpm[26] = 1
	print(fpm)

	mkl_lib.zfeast_hcsrev(
		ctypes.byref(ctypes.c_char(bytes(c_uplo))), ctypes.byref(ctypes.c_int(n)), 
		a, ia, ja, c_fpm, ctypes.byref(espout), ctypes.byref(loop),
		ctypes.byref(c_emin), ctypes.byref(c_emax), ctypes.byref(c_m0), c_e, c_v,
		ctypes.byref(m), c_res, ctypes.byref(info)
		)

	return e, v, m.value, info

# A = sp.csr_matrix(np.diag(np.arange(1, 10)), dtype=complex)
# e, v, m = feast('L', A, 5, 0.5, 2.5)
# print(m, e, v)

# print('a')
# A = A.todense()
# print(A @ v[:, 1])