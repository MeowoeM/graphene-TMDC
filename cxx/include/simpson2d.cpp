#include "simpson2d.h"
#include <iostream>

template <typename T, typename U>
T simpson2d(std::function<T(U x, U y)> f, U xMin, U xMax, 
										  U yMin, U yMax,
										  int m, int n)
{
	U h = (xMax - xMin) / static_cast<U>(m);
	U k = (yMax - yMin) / static_cast<U>(n);

	int xLen = 2 * m + 1;
	int yLen = 2 * n + 1;

	T simpsonCoefficient[yLen][xLen];
	// std::array<std::array<T, 2 * n + 1>, 2 * m + 1> functionValueGrid;

	simpsonCoefficient[0][0] = 1.0f;
	simpsonCoefficient[0][xLen - 1] = 1.0f;

	for(int i = 1; i <= xLen - 1; i++){
		simpsonCoefficient[0][i] = 3.0f - std::pow(-1.0f, i);
	} 

	for(int i = 0; i <= xLen ; i++){
		simpsonCoefficient[yLen - 1][i] = simpsonCoefficient[0][i];
	}

	for(int i = 1; i <= yLen - 1; i++){
		for(int j = 0; j <= xLen; j++){
			simpsonCoefficient[i][j] = (3.0f - std::pow(-1.0f, i)) * simpsonCoefficient[0][j];
		}
	}

	std::cout << simpsonCoefficient[i][j]

	for(int i = 0; i < yLen; i++){
		for(int j = 0; j < xLen; j++){
			std::cout << simpsonCoefficient[i][j] << " ";
		}
		std::cout << "\n";
	}

	U sum = 0.0;

	for(int i = 0; i < yLen; i++){
		for(int j = 0; j < xLen; j++){
			sum += simpsonCoefficient[i][j] * f(static_cast<U>(j - n) * k, static_cast<U>(i - m) * h);
		}
	}
}

template double simpson2d<double, double>(std::function<double(double, double), double, double, double, double, int, int>);