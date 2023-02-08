#pragma once

#include "CMyVektor.h"

class DGLSolver {
private:
	CMyVektor(*f_DGL_System_ersteOrdnung)(CMyVektor y, double x);
	double(*f_DGL_hoehereOrdnung)(CMyVektor y, double x);
	bool hoehereOrdnung;

	CMyVektor ableitungen(CMyVektor y, double x);
public:
	DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x));
	DGLSolver(double(*f_DGL_hoehereOrdnung)(CMyVektor y, double x));

	double eulerVerfahren(double xStart, double xEnd, int steps, CMyVektor yStart);
	double heunVerfahren(double start, double end, int schritte, CMyVektor y_Start);

	double eulerVerfahrenOhneAusgaben(double xStart, double xEnd, int steps, CMyVektor yStart);
	double heunVerfahrenOhneAusgaben(double xStart, double xEnd, int steps, CMyVektor yStart);
};