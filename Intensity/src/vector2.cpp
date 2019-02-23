/*Copied from https://github.com/MikitaS/4_semester_MIPT/blob/master/MathVector2D/  */


#include <iostream>
#include <cmath>
#include "vector2.h"

///Friends input, output:
std::ostream & operator << (std::ostream & os, vector const & vect)
{
	os << vect.x << " " << vect.y;
	return os;
}

std::istream & operator >> (std::istream & is, vector & vect)
{
	is >> vect.x >> vect.y;
	return is;
}

///Constructors:
vector::vector() : x(0), y(0) {}

vector::vector(double amx, double amy) : x(amx), y(amy) {}

vector::vector(vector const & other)
{
	this->x = other.x;
	this->y = other.y;
}

///Non-inline methods:
vector & vector::invert()
{
	double swaper = this->x;
	this->x = this->y;
	this->y = swaper;
}

vector vector::norm() const
{
	double len = this->length();
	return vector(x / len, y / len);
}

///Operators:
vector & vector::operator=(vector const & other)
{
	this->x = other.x;
	this->y = other.y;
	return *this;
}

vector & vector::operator+=(vector const & other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

vector & vector::operator-=(vector const & other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

vector vector::operator+(vector const & other) const
{
	return vector(x + other.x, y + other.y);
}

vector vector::operator-(vector const & other) const
{
	return vector(x - other.x, y - other.y);
}

double vector::operator*(vector const & other) const
{
	return sqrt(x*other.x + y * other.y);
}

double vector::operator^(vector const & other) const
{
	return x * other.y - y * other.x;
}

vector vector::operator+() const
{
	return *this;
}

vector vector::operator-() const
{
	return vector(-x, -y);
}

vector vector::operator*(double num) const
{
	return vector(x*num, y*num);
}

vector vector::operator/(double num) const
{
	return vector(x / num, y / num);
}

vector operator*(double num, vector const & vect)
{
	return vector(vect.x*num, vect.y*num);
}

double vector::get_x()
{
	return x;
}

double vector::get_y()
{
	return y;
}

///Destructor:
vector::~vector() {}