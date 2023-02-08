#pragma once

#include "CZufall.h"

#include <vector>

class CLotto {
	int k, n;	// k ist die Anzahl an Kreuzen die man macht, n ist die range die jedes Kreuz haben darf "6 aus 49"
	CZufall zahl;
	std::vector<int> tippzettel;
public:
	CLotto(int k, int n, int s);
	std::vector<int> simulation();
	int ziehung();
	void setTipps(std::vector<int> tipps);
};