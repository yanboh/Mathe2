#pragma once

#include <iostream>
#include <vector>

class CMyVektor {
private:
    //Memberattribute
    int dim;
    std::vector<double> values;
public:
    // Konstruktoren
    CMyVektor();
    CMyVektor(int _dim, double value = 0.0);

    // getter
    int getDim() const;
    double getComponent(int _dim) const;
    double getLength() const;

    // setter
    void setDim(int _dim);
    void setComponent(int _dim, double value);  // _dim gibt die Dimension an die Veraendert werden soll

    // Operatoren
    CMyVektor operator +(const CMyVektor& a);
    CMyVektor operator -(const CMyVektor& a);
    CMyVektor operator *(double lambda);
    CMyVektor operator /(double lambda);
    double& operator [](int i);
    friend std::ostream& operator <<(std::ostream& stream, const CMyVektor& _vector);
};
