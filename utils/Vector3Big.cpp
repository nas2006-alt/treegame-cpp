#include "Vector3Big.h"

Vector3Big::Vector3Big() {}

Vector3Big::Vector3Big(ttmath::Big<16, 16> x, ttmath::Big<16, 16> y, ttmath::Big<16, 16> z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
