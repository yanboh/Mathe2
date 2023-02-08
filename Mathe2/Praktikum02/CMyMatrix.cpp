#include <iostream>

#include "CMyMatrix.h"
#include "CMyVektor.h"

CMyMatrix::CMyMatrix(int _m) {
	m = _m;
	matrix.assign(_m, CMyVektor());
}

CMyMatrix::CMyMatrix(int _m, int _n) {
	n = _n;
	m = _m;

	matrix.assign(_m, CMyVektor(_n));
}

int CMyMatrix::getM() {
	return m;
}

int CMyMatrix::getN() {
	return n;
}

CMyMatrix CMyMatrix::invers() {
	if (m != 2 || n != 2) {
		std::cout << "Diese Funktion ist nur fuer 2x2 Matrizen gedacht!\n";
		exit(-1);
	}

	double a = matrix[0][0];
	double b = matrix[0][1];
	double c = matrix[1][0];
	double d = matrix[1][1];

	double lambda = 1 / (a * d - b * c);

	CMyMatrix result(2, 2);

	result[0][0] = lambda * d;
	result[0][1] = lambda * b*(-1);
	result[1][0] = lambda * c*(-1);
	result[1][1] = lambda * a;

	return result;
}

CMyVektor& CMyMatrix::operator [](int _dim) {
	return matrix[_dim];
}

CMyVektor CMyMatrix::operator *(CMyVektor vector) {
	if (getN() != vector.getDim()) {
		std::cout << "\n\nUm Matrix*Vektor zu rechnen muessen die n Dim der Matrix und die Dimension des Vektors uebereinstimmen.\n\n";
		exit(-2);
	}

	CMyVektor result(getM());
	
	for (int i = 0; i < getM(); i++)
		for (int j = 0; j < getN(); j++)
			result[i] += (*this)[i][j] * vector[j];

	return result;
}

std::ostream& operator <<(std::ostream& stream, CMyMatrix& matrix) {
	for (int i = 0; i < matrix.getM(); i++)
		stream << "\t" << matrix[i] << std::endl;

	return stream;
}