#pragma once
#include <iostream>

class CKomplex {
	double x, y;

public:
	//Konstruktoren
	CKomplex();
	CKomplex(double x, double y);
	CKomplex(double phi);
	CKomplex(const CKomplex& z);	//Copy-Konstruktor ist wichtig weil ansonsten std::vector meckert wegen template Vorlage

	//Destruktor
	~CKomplex();

	//getter
	double re() const;
	double im() const;

	//Methoden
	double abs() const;

	//Operatoren
	CKomplex operator +(const CKomplex& z);
	CKomplex operator *(const CKomplex& z);
	CKomplex operator *(double faktor);
	CKomplex& operator +=(const CKomplex& z);

	friend std::ostream& operator <<(std::ostream& stream, const CKomplex& z);
};