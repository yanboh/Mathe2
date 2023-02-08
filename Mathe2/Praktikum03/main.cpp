#include <iostream>
#include <math.h>

#include "Funktionen.h"
#include "DGLSolver.h"

int main() {
	DGLSolver solverTest(Bsp2);
	CMyVektor yTest(2);
	yTest[0] = 2;
	yTest[1] = -1;

	DGLSolver system(DGLSystem);
	CMyVektor ySystem(2);
	ySystem[0] = 0;
	ySystem[1] = 1;

	DGLSolver hoehereOrdnung(DGLDritterOrdnung);
	CMyVektor yHoehereOrdnung(3);
	yHoehereOrdnung[0] = 1.0;
	yHoehereOrdnung[1] = -1.0;
	yHoehereOrdnung[2] = 2.0;

	bool acceptableInput = false;
	int inputChoice, inputSteps;

	while (!acceptableInput) {
		std::cout << "Bitte waehlen Sie eine der folgenden Funktionen:\n\n"
			<< "Ihre Optionen :\n\n"
			<< "[1]: Eulerverfahren mit der gegebenen DGL hoeherer Ordnung\n"
			<< "[2]: Heunverfahren mit der gegebenen DGL hoeherer Ordnung\n\n"
			<< "[3]: Eulerverfahren mit dem gegebenen DGL System\n"
			<< "[4]: Heunverfahren mit dem gegebenen DGL System\n\n"
			<< "[5]: Abweichungen zu beiden Verfahren, mit allen angegebenen Schrittweiten bei DGL hoeherer Ordnung ausgeben.\n\n"
			<< "Ihre Eingabe bitte: ";
		std::cin >> inputChoice;
		std::cout << std::endl;

		switch (inputChoice) {
		default:
			std::cout << "\nSie haben eine ungueltige Eingabe getaetigt!\n"
				<< "Bitte Versuchen Sie es noch einmal.\n\n"
				<< "-----------------------------------------------------\n\n";
			break;
		case 1:
			acceptableInput = true;
			std::cout << "Bitte geben Sie die gewuenschte Anzahl Schritte ein: ";
			std::cin >> inputSteps;
			std::cout << "\nIhr gewuenschter Output lautet:\n\n";
			hoehereOrdnung.eulerVerfahren(1.0, 2.0, inputSteps, yHoehereOrdnung);
			break;
		case 2:
			acceptableInput = true;
			std::cout << "Bitte geben Sie die gewuenschte Anzahl Schritte ein: ";
			std::cin >> inputSteps;
			std::cout << "\nIhr gewuenschter Output lautet:\n\n";
			hoehereOrdnung.heunVerfahren(0.0, 2.0, inputSteps, yHoehereOrdnung);
			break;
		case 3:
			acceptableInput = true;
			std::cout << "Bitte geben Sie die gewuenschte Anzahl Schritte ein: ";
			std::cin >> inputSteps;
			std::cout << "\nIhr gewuenschter Output lautet:\n\n";
			system.eulerVerfahren(0.0, 2.0, inputSteps, ySystem);
			break;
		case 4:
			acceptableInput = true;
			std::cout << "Bitte geben Sie die gewuenschte Anzahl Schritte ein: ";
			std::cin >> inputSteps;
			std::cout << "\nIhr gewuenschter Output lautet:\n\n";
			system.heunVerfahren(0.0, 2.0, inputSteps, ySystem);
			break;
		case 5:
			acceptableInput = true;
			std::cout << "Ihr gewuenschter Output lautet:\n\n";
			abweichungenAusgeben(hoehereOrdnung, yHoehereOrdnung);
			break;
		}
	}
}