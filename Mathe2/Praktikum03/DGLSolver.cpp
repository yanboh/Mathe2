#include <iostream>
#include "DGLSolver.h"


DGLSolver::DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x)) {
	f_DGL_System_ersteOrdnung = f_DGL_System;
	f_DGL_hoehereOrdnung = nullptr;
	hoehereOrdnung = false;
}

DGLSolver::DGLSolver(double(*f_DGL_System)(CMyVektor y, double x)) {
	f_DGL_hoehereOrdnung = f_DGL_System;
	f_DGL_System_ersteOrdnung = nullptr;
	hoehereOrdnung = true;
}

CMyVektor DGLSolver::ableitungen(CMyVektor y, double x) {
	CMyVektor result(y.getDim());
	if (!hoehereOrdnung) {
		result = f_DGL_System_ersteOrdnung(y, x);
		return result;
	}

	for (int i = 0; i < (y.getDim() - 1); i++)
		result[i] = y[i + 1];

	result[y.getDim() - 1] = f_DGL_hoehereOrdnung(y, x);

	return result;
}

double DGLSolver::eulerVerfahren(double xStart, double xEnd, int steps, CMyVektor yStart) {
	if (steps < 1) {
		std::cout << "Fehlerhafte Eingabe!\n"
				<< "Bitte geben sie eine Schrittzahl > 0 an.\n\n";
		return -1;
	}

	double diff = xEnd - xStart;
	double h = diff / (double)steps;
	std::cout << "\nh = " << h << std::endl << std::endl;

	for (int i = 0; i < steps; i++) {
		std::cout << "Schritt " << i << ":"
				<< "\n\tx = " << xStart
				<< "\n\ty = " << yStart;

		double yNext = xStart + (diff * (double)i) / (double)steps;
		std::cout << "\n\ty' = " << ableitungen(yStart, yNext) << std::endl << std::endl;
		
		yStart = yStart + (ableitungen(yStart, xStart) * h);
		xStart += h;
	}

	std::cout << "Ende Bei:"
			<< "\n\tx = " << xEnd
			<< "\n\ty = " << yStart
			<< std::endl << std::endl;

	std::cout << "Abweichung bei " << steps << " Schritten: " << (yStart[0] - 0.5) << std::endl;

	return (yStart[0] - 0.5);
}

double DGLSolver::eulerVerfahrenOhneAusgaben(double xStart, double xEnd, int steps, CMyVektor yStart) {
	double diff = xEnd - xStart;
	double h = diff / (double)steps;

	for (int i = 0; i < steps; i++) {
		double yNext = xStart + (diff * (double)i) / (double)steps;

		yStart = yStart + (ableitungen(yStart, xStart) * h);
		xStart += h;
	}

	return (yStart[0] - 0.5);
}

double DGLSolver::heunVerfahren(double xStart, double xEnd, int steps, CMyVektor yStart)
{
	double h = (xEnd - xStart) / steps;

	std::cout << "h = " << h << std::endl;
	CMyVektor ableitungOrigin, testMitEuler, ableitungNachTest, mittelAbleitungen;

	for (int i = 0; i < steps; i++) {
		std::cout << "Schritt " << i << std::endl
				<< "\tx = " << xStart << std::endl
				<< "\ty = " << yStart << std::endl;

		ableitungOrigin = ableitungen(yStart, xStart);
		std::cout << "\ty'_orig = " << ableitungOrigin << std::endl << std::endl;

		testMitEuler = yStart + (ableitungen(yStart, xStart) * h);
		std::cout << "\ty_Test = " << testMitEuler << std::endl;

		ableitungNachTest = ableitungen(testMitEuler, xStart + h);
		std::cout << "\ty'_Test = " << ableitungNachTest << std::endl << std::endl;

		mittelAbleitungen = (ableitungOrigin + ableitungNachTest) * 0.5;
		std::cout << "\ty'_Mittel = " << mittelAbleitungen << std::endl << std::endl;

		yStart = yStart + (mittelAbleitungen * h);	//Euler-Schritt
		xStart += h;
	}

	std::cout << "Ende Bei:"
			<< "\n\tx = " << xEnd
			<< "\n\ty = " << yStart
			<< std::endl << std::endl;

	std::cout << "Abweichung bei " << steps << " Schritten: " << (yStart[0] - 0.5) << std::endl << std::endl;

	return (yStart[0] - 0.5);
}

double DGLSolver::heunVerfahrenOhneAusgaben(double xStart, double xEnd, int steps, CMyVektor yStart)
{
	double h = (xEnd - xStart) / steps;

	CMyVektor ableitungOrigin, testMitEuler, ableitungNachTest, mittelAbleitungen;

	for (int i = 0; i < steps; i++) {
		ableitungOrigin = ableitungen(yStart, xStart);
		testMitEuler = yStart + (ableitungen(yStart, xStart) * h);
		ableitungNachTest = ableitungen(testMitEuler, xStart + h);
		mittelAbleitungen = (ableitungOrigin + ableitungNachTest) * 0.5;

		yStart = yStart + (mittelAbleitungen * h);	//Euler-Schritt
		xStart += h;
	}

	return (yStart[0] - 0.5);
}
