#pragma once

#include <iostream>
#include <cmath>

class vector3
{
	float x;
	float y;
	float z;
public:
	vector3(float a = 0, float b = 0, float c = 0);
	friend std::ostream& operator<<(std::ostream& stream, const vector3& v);
	friend std::istream& operator>>(std::istream& stream, vector3& v);
	vector3 operator+(const vector3 & other) const;
	vector3 &operator+=(const vector3 & other);
	vector3 operator-(const vector3 & other) const;
	vector3 &operator-=(const vector3 & other);
	float operator*(const vector3 & other) const;
	vector3 operator^(const vector3 & other) const;
	vector3 operator*(float other) const;
	friend vector3 operator*(float other, const vector3 & v);
	vector3 operator/(float other) const;
	vector3 norm();
	float len();
	vector3 operator-() const;
};