#include <math.h>
#include "CKomplex.h"

//Konstruktoren
CKomplex::CKomplex() {
	x = 0.0;
	y = 0.0;
}

CKomplex::CKomplex(double x_neu, double y_neu) {
	x = x_neu;
	y = y_neu;
}

CKomplex::CKomplex(double phi) {
	x = cos(phi);
	y = sin(phi);
}

CKomplex::CKomplex(const CKomplex& z) {
	x = z.x;
	y = z.y;
}

//Destruktor
CKomplex::~CKomplex(){}

//getter
double CKomplex::re() const {
	return x;
}

double CKomplex::im() const {
	return y;
}

//Methoden
double CKomplex::abs() const {
	return sqrt((x * x) + (y * y));
}

//Operatoren
CKomplex CKomplex::operator +(const CKomplex& z) {
	double re = (this->x + z.x);
	double im = (this->y + z.y);
	CKomplex result(re, im);
	return result;
}

CKomplex CKomplex::operator *(const CKomplex& z) {
	//z1 = x1 + y1 * i
	double x1 = this->x;
	double y1 = this->y;

	//z2 = x2 + y2 * i
	double x2 = z.x;
	double y2 = z.y;

	double re = (x1*x2 - y1*y2);
	double im = (x1*y2 + x2*y1);

	CKomplex result(re, im);
	return result;
}

CKomplex CKomplex::operator *(double faktor) {
	CKomplex result = *this;
	result.x *= faktor;
	result.y *= faktor;
	return result;
}

CKomplex& CKomplex::operator +=(const CKomplex& z) {
	this->x += z.x;
	this->y += z.y;
	return *this;
}

std::ostream& operator <<(std::ostream& stream, const CKomplex& z) {
	stream << z.x << " + (" << z.y << ") * j\n";
	return stream;
}