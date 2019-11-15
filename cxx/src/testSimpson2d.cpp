#include <iostream>
#include <ctime>
#include "simpson2d.h"
// #include <random>

double f(double x, double y)
{
	return exp(-(x * x + y * y));
}

int main(int argc, char const *argv[])
{
	int start_s=clock();

	double tmp = simpson2d<double, double>(f, -4.0f, 4.0f, -4.0f, 4.0f, 256, 256);
	
	int stop_s=clock();
	std::cout.precision(17);
	std::cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << ", result: " << std::fixed << tmp << std::endl;

	return 0;
}