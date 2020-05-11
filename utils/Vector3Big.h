#pragma once
#include <ttmath/ttmath.h>
class Vector3Big
{
public:
	ttmath::Big<16, 16> x = 0, y = 0, z = 0;
	Vector3Big(ttmath::Big<16, 16> x, ttmath::Big<16, 16> y, ttmath::Big<16, 16> z);
	Vector3Big();
};

