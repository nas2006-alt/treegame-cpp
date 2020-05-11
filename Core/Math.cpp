#include "Math.h"

std::string Math::BigToString(ttmath::Big<16, 16> big)
{
	std::string string;
	if (big < 1000) {
		ttmath::Big<16, 16> temp(big);
		temp *= 10;
		temp.Round();
		temp /= 10;
		string = temp.ToString();
	}
	else {
		big.ToString(string, 10, true, 15, 1, true, '.');
		replaceOccurancesOf(string, '+', "", string);
	}

	if (string.find('.') == std::string::npos) {
		string += ".0";
	}

	return string;
}
