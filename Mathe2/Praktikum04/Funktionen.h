#pragma once
#include <fstream>   
#include <vector>
#include <math.h>

#include "CKomplex.h"

std::vector<CKomplex> werte_einlesen(const std::string dateiname);
void werte_ausgeben(const std::string dateiname, std::vector<CKomplex> werte, double epsilon);

std::vector<CKomplex> FourierTransformation(std::vector<CKomplex> f, bool hin);

void abweichungenAusgeben();
void ausgabeExplizitesEpsilon();