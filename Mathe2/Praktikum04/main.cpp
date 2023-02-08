#include <iostream>
#include <fstream>
#include <vector>

#include "CKomplex.h"
#include "Funktionen.h"

int main() {
	bool acceptableInput = false;
	int input;

	/*std::vector<CKomplex> datenpunkte;
	datenpunkte.resize(4);

	CKomplex datenpunkt1(0, -2);
	CKomplex datenpunkt2(2, -1);
	CKomplex datenpunkt3(2, 1);
	CKomplex datenpunkt4(3, -3);

	datenpunkte[0] = datenpunkt1;
	datenpunkte[1] = datenpunkt2;
	datenpunkte[2] = datenpunkt3;
	datenpunkte[3] = datenpunkt4;

	std::vector<CKomplex> results = FourierHinTransformation(datenpunkte);

	for (int i = 0; i < results.size(); i++) {
		std::cout << results[i];
	}*/

	while (!acceptableInput) {
		std::cout << "Bitte waehlen Sie eine der folgenden Funktionen:\n\n"
			<< "Ihre Optionen :\n"
			<< "[1]: Alle Abweichungen ausgeben\n"
			<< "[2]: Abweichung zu explizitem Epsilon ausgeben\n\n"
			<< "Ihre Eingabe bitte: ";
		std::cin >> input;
		std::cout << std::endl;

		switch (input) {
		default:
			std::cout << "\nSie haben eine ungueltige Eingabe getaetigt!\n"
				<< "Bitte Versuchen Sie es noch einmal.\n\n"
				<< "-----------------------------------------------------\n\n";
			break;
		case 1:
			acceptableInput = true;
			abweichungenAusgeben();
			break;
		case 2:
			acceptableInput = true;
			ausgabeExplizitesEpsilon();
			break;
		}
	}
}