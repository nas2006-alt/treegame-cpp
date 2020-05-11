#pragma once
#include <vector>
#include <ttmath/ttmath.h>
#include "Constants.h"
#include <math.h>
class Player
{
public:
	static ttmath::Big<16, 16> x, y, z;
	static ttmath::Big<8, 8> RP;
	static std::vector<ttmath::Big<16, 16>> Rates;
	static std::vector<bool> upgrades, rbUpgrades;
	static void initConstants();
	static void reset(bool keepRp);
	static void calcRates();
	static void calcX(), calcY(), calcZ();
};

