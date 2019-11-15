#ifndef SIMPSON2D_H
#define SIMPSON2D_H

#include <functional>
#include <array>
#include <cmath>

template <class T, class U>
T simpson2d(std::function<T(U x, U y)> f, U xMin, U xMax, 
										  U yMin, U yMax,
										  int m, int n)
{
	U h = (xMax - xMin) / static_cast<U>(m);
	U k = (yMax - yMin) / static_cast<U>(n);

	int xLen = 2 * m + 1;
	int yLen = 2 * n + 1;

	// std::cout << "a \n";

	// T simpsonCoefficient[yLen][xLen];
	// // std::array<std::array<T, 2 * n + 1>, 2 * m + 1> functionValueGrid;

	// simpsonCoefficient[0][0] = 1.0f;
	// simpsonCoefficient[0][xLen - 1] = 1.0f;

	// for(int i = 1; i <= xLen - 2; i++){
	// 	simpsonCoefficient[0][i] = 3.0f - std::pow(-1.0f, i);
	// } 

	// std::cout << "a \n";

	// for(int i = 0; i <= xLen ; i++){
	// 	simpsonCoefficient[yLen - 1][i] = simpsonCoefficient[0][i];
	// }

	// std::cout << "a \n";

	// for(int i = 1; i <= yLen - 2; i++){
	// 	for(int j = 0; j <= xLen; j++){
	// 		simpsonCoefficient[i][j] = (3.0f - std::pow(-1.0f, i)) * simpsonCoefficient[0][j];
	// 	}
	// }

	// std::cout << "a \n";

	// for(int i = 0; i < yLen; i++){
	// 	for(int j = 0; j < xLen; j++){
	// 		std::cout << simpsonCoefficient[i][j] << "\t";
	// 	}
	// 	std::cout << "\n";
	// }

	U sum = 0.0;

	sum += f(static_cast<U>(0    - n) * k, static_cast<U>(0    - m) * h);
	sum += f(static_cast<U>(0    - n) * k, static_cast<U>(yLen - m) * h);
	sum += f(static_cast<U>(xLen - n) * k, static_cast<U>(0    - m) * h);
	sum += f(static_cast<U>(xLen - n) * k, static_cast<U>(yLen - m) * h);

	for(int i = 1; i < xLen - 1; i++){
		sum += (3.0f - std::pow(-1.0f, i)) * f(static_cast<U>(i - n) * k, static_cast<U>(0    - m) * h);
		sum += (3.0f - std::pow(-1.0f, i)) * f(static_cast<U>(i - n) * k, static_cast<U>(yLen - m) * h);
	}

	for(int i = 1; i < yLen - 1; i++){
		sum += (3.0f - std::pow(-1.0f, i)) * f(static_cast<U>(0    - n) * k, static_cast<U>(i - m) * h);
		sum += (3.0f - std::pow(-1.0f, i)) * f(static_cast<U>(yLen - n) * k, static_cast<U>(i - m) * h);
	}

	for(int i = 1; i < yLen - 1; i++){
		for(int j = 1; j < xLen - 1; j++){
			sum += (3.0f - std::pow(-1.0f, i)) * 
			       (3.0f - std::pow(-1.0f, j)) * 
			       f(static_cast<U>(j - n) * k, static_cast<U>(i - m) * h);
		}
	}

	return sum * h * k / 9.0;
}

#endif