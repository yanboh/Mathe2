#include <iostream>

#include "CMyMatrix.h"
#include "funktionen.h"
#include "test.h"

void testMultiplikation() {
	CMyMatrix matrix1(3, 3);
	CMyVektor a(3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix1[i][j] = double(i + j + 1);
		}
		a[i] = double(i + 3);
	}

	std::cout << "Matrix:\n" << matrix1;
	std::cout << "\nVector:\n" << a;
	std::cout << "\n\nProdukt:\n" << matrix1 * a;
	std::cout << std::endl;
}

void testInverse() {
	CMyMatrix matrix1(2, 2);

	for (int i = 0; i < matrix1.getM(); i++)
		for (int j = 0; j < matrix1.getN(); j++) {
			matrix1[i][j] = double(i + j + 1);
		}

	CMyMatrix matrix1Inverse = matrix1.invers();

	std::cout << matrix1 << std::endl << std::endl;
	std::cout << matrix1Inverse << std::endl;
}

void testJacobi() {
	CMyVektor start(4, 0.0);
	start[0] = 1;
	start[1] = 2;
	start[2] = 0;
	start[3] = 3;

	CMyMatrix result = jacobi(start, function);

	std::cout << "Start vector:\n" << start << std::endl << std::endl;
	std::cout << "Jacobi Matrix:\n" << result << std::endl << std::endl;
}

void testNewtonverfahren() {
	CMyVektor start(2);
	start[0] = 1;
	start[1] = 1;

	newtonverfahren(start, functionJacobi, 0);
}