#include "Vector3.h"
#include<iostream>

Vector3B::Vector3B()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3B::Vector3B(double t_x, double t_y, double t_z):
	x(t_x),
	y(t_y),
	z(t_z)
{
}

double Vector3B::returnLength()
{
	return std::sqrt((x * x) + (y * y) + (z * z));
}

void Vector3B::normalize()
{
	double length = returnLength();
	x /= length;
	y /= length;
	z /= length;
}
