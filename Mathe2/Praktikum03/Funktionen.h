#pragma once
#include "CMyVektor.h"
#include "DGLSolver.h"

CMyVektor Bsp2(CMyVektor y, double x);
CMyVektor DGLSystem(CMyVektor y, double x);
double DGLDritterOrdnung(CMyVektor y, double x);

void abweichungenAusgeben(DGLSolver hoehereOrdnung, CMyVektor yHoehereOrdnung);