#include "Funktionen.h"

//Differenzialgleichungen

CMyVektor Bsp2(CMyVektor y, double x) {
	CMyVektor result(y.getDim());
	result[0] = y[1];
	result[1] = x - x * x * y[1] * y[0];
	return result;
}

CMyVektor DGLSystem(CMyVektor y, double x) {
	CMyVektor result(y.getDim());
	result[0] = (2.0 * y[1]) - (x * y[0]);
	result[1] = (y[0] * y[1]) - (2.0 * x * x * x);
	return result;
}

double DGLDritterOrdnung(CMyVektor y, double x) {
	return (2.0 * x * y[1] * y[2]) + (2.0 * y[0] * y[0] * y[1]);
}

/*************************************************************************************/

//Ausgaben Abweichungen

void abweichungenAusgeben(DGLSolver hoehereOrdnung, CMyVektor yHoehereOrdnung) {
	for (int i = 10; i <= 10000; i *= 10) {
		double resultEuler = hoehereOrdnung.eulerVerfahrenOhneAusgaben(1.0, 2.0, i, yHoehereOrdnung);
		double resultHeun = hoehereOrdnung.heunVerfahrenOhneAusgaben(1.0, 2.0, i, yHoehereOrdnung);
		std::cout << "Abweichung bei Euler bei " << i << " Schritten: " << resultEuler
				<< "\nAbweichung bei Heun  bei " << i << " Schritten: " << resultHeun
				<< std::endl << std::endl;
	}
}