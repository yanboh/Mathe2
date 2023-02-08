#include "CZufall.h"

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <windows.h>

CZufall::CZufall() {}

int CZufall::wert(int a, int b) {
	return rand() % ((b + 1) - a) + a;
}

void CZufall::initialisiere(int s) {
	srand(s);
}

void CZufall::test(int a, int b, int N) {
	int range = abs((b + 1) - a);
	std::vector<int> results;
	results.resize(range);

	for (int index = 0; index < N; index++) {
		int zahlTmp = wert(a, b);
		for (int indexVector = a, zaehler = 0; indexVector <= b; indexVector++) {
			if (zahlTmp == indexVector)
				results[zaehler]++;
			zaehler++;
		}
	}

	for (int index = 0; index < ((b + 1) - a); index++) {
		std::cout << "Die Zahl " << a + index << " kommt " << results[index] << " mal vor.\n";
	}
}

void CZufall::testFalsch(int a, int b, int N) {	
	int range = abs((b + 1) - a);
	std::vector<int> results;
	results.resize(range);

	for (int index = 0; index < N; index++) {
		initialisiere(time(NULL));
		int zahlTmp = wert(a, b);
		for (int indexVector = a, zaehler = 0; indexVector <= b; indexVector++) {
			if (zahlTmp == indexVector)
				results[zaehler]++;
			zaehler++;
		}
		/*std::cout << "Wert: " << zahlTmp << std::endl;
		Sleep(2000);*/
	}

	for (int index = 0; index < ((b + 1) - a); index++) {
		std::cout << "Die Zahl " << a + index << " kommt " << results[index] << " mal vor.\n";
	}
}