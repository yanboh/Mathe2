#pragma once

#include <iostream>
#include <vector>

#include "CMyVektor.h"

class CMyMatrix {
private:
	int m, n;
	std::vector<CMyVektor> matrix;

public:

	CMyMatrix(int _m);
	CMyMatrix(int _m, int _n);	//m gibt an wie viele Zeilen, n gibt an wie viele Spalten

	int getM();	//Anzahl Zeilen
	int getN();	//Anzahl Spalten

	CMyMatrix invers();

	CMyVektor& operator [](int _dim);
	CMyVektor operator *(CMyVektor vector);
	friend std::ostream& operator <<(std::ostream& stream, CMyMatrix& matrix);
};

