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
    exit(-3);
}

CMyVektor CMyVektor::operator -(const CMyVektor& b) {
    CMyVektor result = *this;
    if (this->getDim() == b.getDim()) {
        for (int i = 0; i < this->getDim(); i++) {
            result[i] -= b.values[i];
        }
        return result;
    }
    std::cout << "ERROR: Vektoren koennen nur subtrahiert werden, wenn sie die gleiche Dimension haben." << std::endl;
    exit(-3);
}

CMyVektor CMyVektor::operator *(double lambda) {
    CMyVektor result = *this;
    for (unsigned i = 0; i < this->getDim(); i++) {
        result[i] *= lambda;
    }
    return result;
}

CMyVektor CMyVektor::operator /(double lambda) {
    CMyVektor result = *this;
    for (unsigned i = 0; i < this->getDim(); i++) {
        result[i] /= lambda;
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