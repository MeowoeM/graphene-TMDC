#include "mkl.h"
#include<iostream>

using namespace std;

#ifdef __cplusplus
extern "C" sparse_struct test()
#else
sparse_struct test()
#endif
{
	sparse_struct handle;
	handle.matrix_structure = MKL_UPPER_TRIANGULAR;
	handle.message_level = MKL_PRINT;
	handle.print_style = MKL_C_STYLE;
	sparse_matrix_checker_init(&handle);
	cout << handle.check_result[0] << '\t' << handle.check_result[1] << '\t' << handle.check_result[2] << endl;
	cout << handle.indexing << endl;
	cout << handle.matrix_structure << endl;
	cout << handle.matrix_format << endl;
	cout << handle.message_level << endl;
	cout << handle.print_style << endl;
	return handle;
}

#ifdef __cplusplus
extern "C" MKL_INT sparse_matrix_check(MKL_INT n, MKL_INT* ia, MKL_INT* ja)
#else
MKL_INT sparse_matrix_check(MKL_INT n, MKL_INT* ia, MKL_INT* ja)
#endif
{
	sparse_struct handle;
	handle.n = n;
	handle.csr_ia = ia;
	handle.csr_ja = ja;
	handle.indexing = MKL_ONE_BASED;
	handle.matrix_structure = MKL_UPPER_TRIANGULAR;
	handle.message_level = MKL_PRINT;
	handle.print_style = MKL_C_STYLE;

	cout << "MKL_SPARSE_CHECKER_SUCCESS: \t" << MKL_SPARSE_CHECKER_SUCCESS << endl;
	cout << "MKL_SPARSE_CHECKER_NON_MONOTONIC: \t" << MKL_SPARSE_CHECKER_NON_MONOTONIC << endl;
	cout << "MKL_SPARSE_CHECKER_OUT_OF_RANGE: \t" << MKL_SPARSE_CHECKER_OUT_OF_RANGE << endl;
	cout << "MKL_SPARSE_CHECKER_NONTRIANGULAR: \t" << MKL_SPARSE_CHECKER_NONTRIANGULAR << endl;
	cout << "MKL_SPARSE_CHECKER_NONORDERED: \t" << MKL_SPARSE_CHECKER_NONORDERED << endl;

	sparse_matrix_checker_init(&handle);
	return sparse_matrix_checker(&handle);
}

// int main(){
// 	sparse_struct tmp = test();
// }