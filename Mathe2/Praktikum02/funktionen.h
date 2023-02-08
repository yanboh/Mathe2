#pragma once

#include "CMyVektor.h"
#include "CMyMatrix.h"


CMyVektor function(CMyVektor pos);
CMyVektor gradient(CMyVektor x, double(*funktion)(CMyVektor pos));
CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor pos));
CMyVektor functionJacobi(CMyVektor pos);
CMyVektor newtonverfahren(CMyVektor x, CMyVektor(*funktion)(CMyVektor pos), int counter);