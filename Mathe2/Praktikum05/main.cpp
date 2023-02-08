#include "CZufall.h"
#include "CLotto.h"

#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

//#define seed 1

//void aufgabeEinsA(int N) {
//	int s = 0;
//	CZufall einsA;
//	for (int index = 1; index <= N; index++) {
//		std::cout << "Durchlauf Nummer " << index << ":\n\n";
//		einsA.initialisiere(s);
//		einsA.test(3, 7, 10000);
//		std::cout << std::endl << std::endl;
//	}
//}
//
//void aufgabeEinsB(int N) {
//	int s = 0;
//	CZufall einsB;
//	for (int index = 1; index <= N; index++) {
//		std::cout << "Durchlauf Nummer " << index << " (s = " << s << "):\n\n";
//		einsB.initialisiere(s);
//		einsB.test(3, 7, 10000);
//		s += 10;
//		std::cout << std::endl << std::endl;
//	}
//}
//
//void aufgabeEinsC(int N) {
//	CZufall einsC;
//	for (int index = 1; index <= N; index++) {
//		std::cout << "Durchlauf Nummer " << index << ":\n\n";
//		einsC.initialisiere(time(NULL));
//		einsC.test(3, 7, 10000);
//		std::cout << std::endl << std::endl;
//		// Sleep(3000);
//	}
//}
//
//void aufgabeEinsD() {
//	CZufall einsD;
//	einsD.testFalsch(3, 7, 10000);
//}
//
//void aufgabeZweiD(int N) {
//	int s = 0;
//	
//	for (int i = 0; i < N; i++) {
//		CLotto spiel(6, 49, s);
//		std::cout << "\nIm Spiel Nummer " << i + 1 << " stimmen " << spiel.ziehung() << " Zahlen ueberein.\n\n"
//			<< "-----------------------------------------------------------------\n\n";
//		s += 10;
//	}
//}
//
//
//
//double monteCarloSim(int r, int k, int n, int N, bool gleicherZettel) {
//	std::vector<int> results(k + 1);
//	CLotto schein(k, n, time(NULL));
//	schein.setTipps(schein.simulation());
//
//	// Spieler der den gleichen Zettel nutzt
//	if (gleicherZettel) {
//		for (int i = 0; i < N; i++) {
//			results[schein.ziehung()]++;
//		}
//		std::cout << N << " Spiele bei gleichen Zetteln:\n\n";
//		outputResults(results);
//		return 100 * double(results[r]) / double(N);
//	}
//
//	// Spieler der jedes mal einen zufaelligen neuen Zettel verwendet
//	for (int i = 0; i < N; i++) {
//		schein.setTipps(schein.simulation());
//		results[schein.ziehung()]++;
//	}
//	std::cout << N << " Spiele bei unterschiedlichen Zetteln:\n\n";
//	outputResults(results);
//	return 100 * double(results[r]) / double(N);
//}

/*******************************************************************************************/

// Interesse Lotto Sim

bool translateInput(char uebergeben) {
	bool badInput = false;
	bool result = false;
	char input = uebergeben;
	
	do {
		if (badInput) {
			std::cout << "Fehlerhafte Eingabe, bitte versuchen Sie es erneut (y/n) : ";
			std::cin >> input;
		}
		if (input == 'y' || input == 'Y'
			|| input == 'n' || input == 'N') {
			badInput = false;
			if (input == 'y' || input == 'Y')
				result = true;
		}
		else
			badInput = true;
	} while (badInput);

	return result;
}

void determineGameMode(int& input) {
	switch (input) {
	case 1:
	case 2:
	case 3:
	case 4:
	}
}

void outputResults(std::vector<int> input) {
	std::cout << "Die Ergebnisse Ihrer Lotto Simulation lauten:\n\n";
	for (int i = 0; i < input.size(); i++) {
		std::cout << i << " richtige: " << input[i] << std::endl;
	}
}

std::vector<int> lottoSim(int k, int n, int N, bool gleicherZettel) {
	std::vector<int> results(k + 1);
	CLotto schein(k, n, time(NULL));
	schein.setTipps(schein.simulation());

	// Spieler der den gleichen Zettel nutzt
	if (gleicherZettel) {
		for (int i = 0; i < N; i++) {
			results[schein.ziehung()]++;
		}
		return results;
	}

	// Spieler der jedes mal einen zufaelligen neuen Zettel verwendet
	for (int i = 0; i < N; i++) {
		schein.setTipps(schein.simulation());
		results[schein.ziehung()]++;
	}
	return results;
}

void clearScreen() {
	system("CLS");
}

void setConfig(int& numberSimulations, int& numberGuesses, int& maxNumber, int& inputGuesses, bool& sameGuesses) {
	std::cout << "\nWie viele Spiele sollen simuliert werden? (Eingabe) : ";
	std::cin >> numberSimulations;

	std::cout << "\nNotiz: 6 aus 49 ist Standart.\nUm 6 aus 49 zu spielen bitte im Folgenden zunaechst 6 und dann 49 eingeben!\n\n";
	std::cout << "Wie viele Kugeln sollen gezogen werden? (Eingabe) : ";
	std::cin >> numberGuesses;

	std::cout << "Was soll der maximale Zahlenwert auf einer Kugel sein? (Eingabe) : ";
	std::cin >> maxNumber;

	std::cout << "\nFuer Ihre Lottoscheine haben Sie 4 verschiedene Optionen:\n\n"
		<< "1: Sie geben einen Schein an und nutzen diesen fuer alle Spiele.\n"
		<< "2: Sie geben jedes Spiel einen neuen Schein an.\n\n"
		<< "3: Sie nutzen einen zufaellig generierten Schein fuer alle Spiele.\n"
		<< "4: Sie nutzen jedes Spiel einen neuen zufaellig generierten Schein.\n\n"
		<< "Ihre Auswahl bitte: ";
	std::cin >> inputGuesses;
	sameGuesses = translateInput(inputGuesses);
}

void playLotto() {
	int numberSimulations = 0;
	int numberGuesses = 0;
	int maxNumber = 0;

	int inputGuesses = 0;
	char inputConfig = '\0';
	char inputEnd = '\0';

	bool end = false;
	bool firstGame = true;	
	bool keepConfig = false;
	bool sameGuesses = false;

	while (!end) {
		if (firstGame) {
			std::cout << "Wilkommen bei der Lotto Simulation, bitte druecken Sie Enter um zu starten!";
			std::cin.get();
			clearScreen();
			std::cout << "Zunaechst muessen Sie ihr Spiel konfigurieren!";
			std::cin.get();
		}

		else {
			clearScreen();
			std::cout << "Wollen Sie fuer die folgende Simulation ihre bestehenden Konfugurationen beibehalten? (y/n) : ";
			std::cin >> inputConfig;
			keepConfig = translateInput(inputConfig);
		}

		if (firstGame || !keepConfig) {
			setConfig(numberSimulations, numberGuesses, maxNumber, inputGuesses, sameGuesses);
		}

		clearScreen();

		std::cout << "Ihre Konfigurationen lauten:\n"
			<< "\nAnzahl simulierter Spiele: " << numberSimulations
			<< "\nHoechstmoegliche Zahl auf Kugel: " << maxNumber
			<< "\nAnzahl der gezogenen Kugeln: " << numberGuesses;
		if (sameGuesses)
			std::cout << "\n\nSie haben gewaehlt, dass Sie jedes Spiel den gleichen Spielzettel behalten wollen.\n";
		else
			std::cout << "\n\nSie haben gewaehlt, dass Sie jedes Spiel einen neuen zufaellig generierten Spielzettel verwenden wollen.\n";
		std::cout << "\nUm die Simulation zu starten druecken Sie Enter!";

		std::cin.ignore(1000000, '\n');
		std::cin.get();
		clearScreen();

		if (numberSimulations >= 1000000)
			std::cout << "Die Simulation kann auf Grund der gewaehlten Anzahl simulierter Spiele einen Moment dauern.\n\n";

		std::vector<int> resultsSimulation = lottoSim(numberGuesses, maxNumber, numberSimulations, sameGuesses);
		outputResults(resultsSimulation);
		std::cout << "\nDruecken Sie Enter um fortzufahren";
		std::cin.get();
		clearScreen();

		std::cout << "Wollen Sie eine weitere Simulation starten? (y/n) : ";
		std::cin >> inputEnd;
		if (translateInput(inputEnd))
			firstGame = false;
		else
			end = true;
	}
}

int main() {
	playLotto();
}