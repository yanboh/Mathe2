#include <iostream>
#include <math.h>
#include "CMyVektor.h"


CMyVektor::CMyVektor() {
    values.assign(1, 0.0);
}

CMyVektor::CMyVektor(int _dim, double value) {
    dim = _dim;
    values.assign(_dim, value);
}

int CMyVektor::getDim() const {
    return dim;
}

double CMyVektor::getComponent(int _dim) const {
    return values[_dim];
}

double CMyVektor::getLength() const {
    double sum = 0;
    for (int i = 0; i < this->getDim(); i++) {
        sum += pow(this->getComponent(i), 2);
    }
    return sqrt(sum);
}

void CMyVektor::setDim(int _dim) {
    dim = _dim;
}

void CMyVektor::setComponent(int _dim, double value) {
    values[_dim] = value;
}

CMyVektor CMyVektor::operator +(const CMyVektor& b) {
    CMyVektor result = *this;
    if (this->getDim() == b.getDim()) {
        for (int i = 0; i < this->getDim(); i++) {
            result[i] += b.values[i];
        }
        return result;
    }
    std::cout << "ERROR: Vektoren koennen nur addiert werden, wenn sie die gleiche Dimension haben." << std::endl;
    return result;
}

CMyVektor CMyVektor::operator *(double lambda) {
    CMyVektor result = *this;
    for (unsigned i = 0; i < this->getDim(); i++) {
        result[i] *= lambda;
    }
    return result;
}

double& CMyVektor::operator [] (int i) {
    return values[i];
}

std::ostream& operator << (std::ostream& stream, const CMyVektor& vector) {
    stream << "(";
    for (unsigned i = 0; i < vector.getDim(); i++) {
        stream << vector.values[i];
        if (i != vector.getDim() - 1)
            stream << "; ";
    }
    stream << ")";
    return stream;
}

/*******************************************************************************************/

void test() {
    CMyVektor test(3), test2(3), test3(3);

    std::cout << "\n\n\nDie Dimension des erstellen Vektors ist: "
        << test.getDim()
        << std::endl << std::endl;

    for (unsigned i = 0; i < 3; i++) {
        test.setComponent(i + 1, i + 1);
        test2.setComponent(i + 1, i + 2);
    }

    std::cout << "Die erste Dimension des Vektors hat den Wert: " << test[1]
        << std::endl << std::endl;

    test.setComponent(2, 9);

    std::cout << "Der Vektor ausgegeben lautet: " << test
        << std::endl << std::endl
        << "Die Laenge des Vektors betraegt: " << test.getLength() << " Einheiten."
        << std::endl << std::endl;

    test3 = test + test2;
    test = test2;

    std::cout << "Test Additionsoperator + : " << test3
        << std::endl << std::endl;

    std::cout << "Test2 (Vektor): " << test2
        << std::endl << std::endl
        << "Test Zuweisung: " << test
        << std::endl << std::endl;

    test * 5;

    std::cout << "Test Multiplikationsoperator * : " << test
        << std::endl << std::endl;

}