#include <iostream>
#include <vector>
#include <math.h>

#include "CMyVektor.h"

double function1(CMyVektor pos) {
    double x = pos.getComponent(0);
    double y = pos.getComponent(1);

    double erg = sin(x * y) + sin(x) + cos(y);
    return erg;
}

double function2(CMyVektor pos) {
    double x = pos.getComponent(0);
    double y = pos.getComponent(1);
    double z = pos.getComponent(2);

    double erg = (-1) * ((2 * pow(x, 2)) - (2 * x * y) + pow(y, 2) + pow(z, 2) - (2 * x) - (4 * z));
    return erg;
}

CMyVektor gradient(CMyVektor x, double(*funktion)(CMyVektor pos)) {
    CMyVektor grad(x.getDim());
    double h = 1e-8;
    double funktionX = funktion(x);

    for (int i = 0; i < x.getDim(); i++) {
        CMyVektor gradTmp(x.getDim());
        gradTmp = x;
        gradTmp[i] += h;
        
        double tmp = (funktion(gradTmp) - funktionX) / h;
        grad[i] = tmp;
    }
    return grad;
}

void gradientenverfahren(CMyVektor x, double(*funktion)(CMyVektor pos), double lambda = 1.0, int counter = 0) {
    CMyVektor grad = gradient(x, funktion);
    CMyVektor vectorStep = x + (grad * lambda);

    double xValue = funktion(x);
    double valueAtFirstStep = funktion(vectorStep);
    double valueAtStep;
    double gradLength = grad.getLength();

    if (counter == 25) {
        std::cout << "Ende wegen Schrittzahl = 25 bei" << std::endl;
        std::cout << "\tx = " << x << std::endl;
        std::cout << "\tlambda = " << lambda << std::endl;
        std::cout << "\tf(x) = " << xValue << std::endl;
        std::cout << "\tgrad f(x) = " << grad << std::endl;
        std::cout << "\t||grad f(x)|| = " << gradLength << std::endl << std::endl;
        return;
    }

    if (gradLength < 1e-5) {
        std::cout << "Ende wegen ||grad f(x)|| < 1e-5 bei" << std::endl;
        std::cout << "\tx = " << x << std::endl;
        std::cout << "\tlambda = " << lambda << std::endl;
        std::cout << "\tf(x) = " << xValue << std::endl;
        std::cout << "\tgrad f(x) = " << grad << std::endl;
        std::cout << "\t||grad f(x)|| = " << gradLength << std::endl << std::endl;
        return;
    }

    std::cout << "Schritt " << counter << ":" << std::endl;
    std::cout << "\tx = " << x << std::endl;
    std::cout << "\tlambda = " << lambda << std::endl;
    std::cout << "\tf(x) = " << xValue << std::endl;
    std::cout << "\tgrad f(x) = " << grad << std::endl;
    std::cout << "\t||grad f(x)|| = " << gradLength << std::endl;
    std::cout << std::endl;
    std::cout << "\tx_neu = " << vectorStep << std::endl;
    std::cout << "\tf(x_neu) = " << valueAtFirstStep << std::endl;
    std::cout << std::endl;

    if (valueAtFirstStep <= xValue) {
        valueAtStep = valueAtFirstStep;
        while (valueAtStep <= xValue) {
            lambda = lambda / 2;
            vectorStep = x + (grad * lambda);
            valueAtStep = funktion(vectorStep);
            std::cout << "\t halbiere Schrittweite (lambda = " << lambda << "):" << std::endl;
            std::cout << "\tx_neu = " << vectorStep << std::endl;
            std::cout << "\tf(x_neu) = " << valueAtStep << std::endl << std::endl;
        }
        gradientenverfahren(vectorStep, funktion, lambda, ++counter);
        return;
    }

    CMyVektor vectorTest = x + (grad * lambda * 2);
    double valueAtTest = funktion(vectorTest);

    std::cout << "\tTest mit doppelter Schrittweite (lambda = " << lambda * 2 << "):" << std::endl;
    std::cout << "\tx_test = " << vectorTest << std::endl;
    std::cout << "\tf(x_test) = " << valueAtTest << std::endl;

    if (valueAtTest > valueAtFirstStep) {
        std::cout << "\tverdoppele Schrittweite!" << std::endl << std::endl;
        gradientenverfahren(vectorTest, funktion, lambda * 2, ++counter);
        return;
    }

    std::cout << "\tbehalte alte Schrittweite!" << std::endl << std::endl;
    gradientenverfahren(vectorStep, funktion, lambda, ++counter);
}

int main() {
    int eingabe;

    CMyVektor vectorFunktion1(2);
    vectorFunktion1.setComponent(0, 0.2);
    vectorFunktion1.setComponent(1, -2.1);

    CMyVektor vectorFunktion2(3);
    vectorFunktion2.setComponent(0, 0);
    vectorFunktion2.setComponent(1, 0);
    vectorFunktion2.setComponent(2, 0);

    std::cout << "Zu welcher Funktion soll das Verfahren gemacht werden?\n1) oder 2)\n";

    do {
        std::cout << "> ";
        std::cin >> eingabe;
    } while (eingabe < 1 || eingabe > 2);
    std::cout << std::endl << std::endl;
    
    switch (eingabe) {
    case 1:
        gradientenverfahren(vectorFunktion1, function1);
        break;
    case 2:
        gradientenverfahren(vectorFunktion2, function2, 0.1);
        break;
    }
}
