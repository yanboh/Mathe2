#include "Funktionen.h"

#define pi 3.14159265358979323846

std::vector<CKomplex> werte_einlesen(const std::string dateiname)
{
	int i, N, idx;
	double re, im;
	std::vector<CKomplex> werte;

	// File oeffnen
	std::ifstream fp;
	fp.open(dateiname);

	// Dimension einlesen
	fp >> N;

	// Werte-Vektor anlegen
	werte.resize(N);
	CKomplex null(0, 0);
	for (i = 0; i < N; i++)
		werte[i] = null;

	// Eintraege einlesen und im Werte-Vektor ablegen
	while (!fp.eof())
	{
		fp >> idx >> re >> im;
		CKomplex a(re, im);
		werte[idx] = a;
	}

	// File schliessen
	fp.close();

	return werte;
}

void werte_ausgeben(const std::string dateiname, std::vector<CKomplex> werte, double epsilon)
{
	int i;
	int N = werte.size();

	// File oeffnen
	std::ofstream fp;
	fp.open(dateiname);

	// Dimension in das File schreiben
	fp << N << std::endl;

	// Eintraege in das File schreiben
	fp.precision(10);
	for (i = 0; i < N; i++)
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].re() << "\t" << werte[i].im() << std::endl;

	// File schliessen
	fp.close();
}

/***********************************************************************************************/

//Fourier Transformationen

std::vector<CKomplex> FourierTransformation(std::vector<CKomplex> f, bool hin) {
	int N = f.size();
	double vorfaktor = 1 / sqrt(N);
	double phi = 0;

	std::vector<CKomplex> result;
	result.resize(N);

	for (int n = 0; n < N; n++) {
		CKomplex resultSum;
		for (int k = 0; k < N; k++) {
			hin ? phi = ((-1) * (2 * pi * k * n) / N)
				: phi = ((2 * pi * k * n) / N);
			CKomplex sumTmp(phi);
			resultSum += (f[k] * sumTmp);
		}
		CKomplex cn = resultSum * vorfaktor;
		result[n] = cn;
	}

	return result;
}

/***********************************************************************************************/

//maximale Abweichung

double maxAbweichung(std::vector<CKomplex> original, std::vector<CKomplex> results) {
	double result = original[0].re() - results[0].re();
	int N = original.size();

	for (int i = 0; i < N; i++) {
		if (original[i].re() - results[i].re() > result)
			result = original[i].re() - results[i].re();
	}

	return result;
}

/***********************************************************************************************/

//Ausgaben

void abweichungenAusgeben() {
	std::vector<CKomplex> datenpunkte = werte_einlesen("DatenOriginal.txt");
	std::vector<CKomplex> resultsHin = FourierTransformation(datenpunkte, true);
	
	werte_ausgeben("DatenNachHintransformation.txt", resultsHin, -1.0);
	std::vector<CKomplex> ruecktransfo = werte_einlesen("DatenNachHintransformation.txt");
	std::vector<CKomplex> resultsRueck = FourierTransformation(ruecktransfo, false);
	werte_ausgeben("DatenNachRuecktransformation.txt", resultsRueck, -1.0);
	std::cout << "Maximale Abweichung bei Standard-Epsilon: ca. "
		<< maxAbweichung(datenpunkte, resultsRueck) << std::endl;

	for (double epsilon = 0.001; epsilon <= 1; epsilon *= 10) {
		werte_ausgeben("DatenNachHintransformation.txt", resultsHin, epsilon);
		std::vector<CKomplex> ruecktransfo = werte_einlesen("DatenNachHintransformation.txt");
		std::vector<CKomplex> resultsRueck = FourierTransformation(ruecktransfo, false);
		werte_ausgeben("DatenNachRuecktransformation.txt", resultsRueck, epsilon);
		std::cout << "Maximale Abweichung bei epsilon = " << epsilon << ": "
				<< maxAbweichung(datenpunkte, resultsRueck) << std::endl;
	}
}

void ausgabeExplizitesEpsilon() {
	double epsilon;
	std::cout << "\nBitte geben Sie das gewuenschte Epsilon ein: ";
	std::cin >> epsilon;
	std::cout << "\nErgebnis der Berechnung:\n";

	std::vector<CKomplex> datenpunkte = werte_einlesen("DatenOriginal.txt");
	std::vector<CKomplex> resultsHin = FourierTransformation(datenpunkte, true);

	werte_ausgeben("DatenNachHintransformation.txt", resultsHin, epsilon);
	std::vector<CKomplex> ruecktransfo = werte_einlesen("DatenNachHintransformation.txt");
	std::vector<CKomplex> resultsRueck = FourierTransformation(ruecktransfo, false);
	werte_ausgeben("DatenNachRuecktransformation.txt", resultsRueck, epsilon);
	std::cout << "Maximale Abweichung bei Epsilon = " << epsilon << ": "
		<< maxAbweichung(datenpunkte, resultsRueck) << std::endl;
}