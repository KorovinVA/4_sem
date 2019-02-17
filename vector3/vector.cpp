#include "vector.h"
#include <iostream>


std::ostream & operator<<(std::ostream & stream, const vector3 & v)
{
	stream << v.x << " " << v.y << " " << v.z;
	return stream;
}

std::istream & operator>>(std::istream & stream, vector3 & v)
{
	stream >> v.x >> v.y >> v.z;
	return stream;
}

vector3 operator*(float other, const vector3 & v)
{
	return vector3(other * v.x, other * v.y, other * v.z);
}

vector3 vector3::operator+(const vector3 & other) const
{
	return vector3(x + other.x, y + other.y, z + other.z);
}

vector3 &vector3::operator+=(const vector3 & other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return (*this);
}

vector3 vector3::operator-(const vector3 & other) const
{
	return vector3(x - other.x, y - other.y, z - other.z);
}

vector3 & vector3::operator-=(const vector3 & other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return (*this);
}

float vector3::operator*(const vector3 & other) const
{
	return x * other.x + y * other.y + z * other.z;
}

vector3 vector3::operator^(const vector3 & other) const
{
	vector3 temp;
	temp.x = y * other.z - z * other.y;
	temp.y = z * other.x - x * other.z;
	temp.z = x * other.y - y * other.x;
	return temp;
}

vector3 vector3::operator*(float other) const
{
	return vector3(x * other, y * other, z * other);
}

vector3 vector3::operator/(float other) const
{
	return vector3(x / other, y / other, z / other);
}

vector3 vector3::norm()
{
	return vector3(x, y, z)/sqrt(x * x + y * y + z * z);
}

float vector3::len()
{
	return sqrt(x * x + y * y + z * z);
}

vector3 vector3::operator-() const
{
	return vector3(0 - x, 0 - y, 0 - z);
}

vector3::vector3(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}
