#include "feast.h"
#include <iostream>

void feast(
	char * uplo, int n, 
	MKL_Complex16 * a, MKL_INT * ia, MKL_INT * ja, 
	double emin, double emax, MKL_INT * m0 
	double * e, MKL_Complex16 * x, MKL_INT * m ,double * res
	){

	int fpm[128];
	double epsout;
	int , info;

	// input matrix are fed by python
	// dummy output eigenenergy and eigenvectors are fed by python

	feastinit()
	zfeast_hcsrev(uplo, n, a, ia, ja, fpm, 
	epsout, loop, emin, emax, m0, e, 
	x, m, res, info
	);
};