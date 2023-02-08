#include "CLotto.h"

#include <time.h>
#include <iostream>

#define init -99999999


CLotto::CLotto(int _k, int _n, int s) {
	k = _k;
	n = _n;
	tippzettel.resize(_n);
	s < 0 ? zahl.initialisiere(time(NULL))
		  : zahl.initialisiere(s);
}

std::vector<int> CLotto::simulation() {
	std::vector<int> results(k);
	bool lsgTmp;

	for (int index = 0; index < k; index++) {
		lsgTmp = false;

		CZufall zahlTmp;
		int candidate = zahlTmp.wert(1, n);

		for (int indexDurchlauf = 0; indexDurchlauf < k; indexDurchlauf++) {
			if (results[indexDurchlauf] == candidate) {
				lsgTmp = true;
				break;
			}
		}

		if (lsgTmp)
			index--;
		else
			results[index] = candidate;
	}

	return results;
}

int CLotto::ziehung() {
	/*int input;
	bool badInputRange = false, badInputDouble = false, badInput = false;
	std::vector<int> check(k, init);

	std::cout << "Der Stimmzettel darf mit Zahlen von 1 bis " << n << " gefuellt werden.\n\n";
	for (int i = 0; i < k; i++) {
		do {
			badInputDouble = false;
			badInputRange = false;

			if (!badInput)
				std::cout << "Bitte machen Sie das " << i + 1 << ". Kreuz: ";
			else
				std::cout << "Fehlerhafte Eingabe, erneut versuchen: ";

			std::cin >> input;

			for (int j = 0; j < k; j++) {
				if (check[j] == input)
					badInputDouble = true;
			}

			tippzettel[i] = input;

			if (tippzettel[i] < 1 || tippzettel[i] > n)
				badInputRange = true;


			if (badInputRange || badInputDouble)
				badInput = true;

			else
				badInput = false;
		} while (badInput);
	}*/

	int count = 0;
	std::vector<int> ergSimulation = simulation();

	for (int indexSim = 0; indexSim < ergSimulation.size(); indexSim++) {
		for (int indexTipps = 0; indexTipps < tippzettel.size(); indexTipps++) {
			if (tippzettel[indexTipps] == ergSimulation[indexSim])
				count++;
		}
	}

	return count;
}

void CLotto::setTipps(std::vector<int> tipps) {
	tippzettel.resize(tipps.size());
	k = tipps.size();

	tippzettel = tipps;
}