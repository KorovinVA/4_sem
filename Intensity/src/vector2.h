/*Copied from https://github.com/MikitaS/4_semester_MIPT/blob/master/MathVector2D/  */


#pragma once
#include <cmath>

class vector
{
public:
	///constructors:
	vector();
	vector(double amx, double amy);
	vector(const vector & other);

	///methods:
	inline double length() const { return sqrt(x*x + y * y); }
	inline double sqlength() const { return x * x + y * y; }
	vector & invert();
	inline double & X() { return this->x; }
	inline double & Y() { return this->y; }
	vector norm() const;
	inline vector perpendicular() const { return vector(y, -x); }

	///Operators:
	vector & operator=(vector const & other);
	vector & operator+=(vector const & other);
	vector & operator-=(vector const & other);

	vector operator+(vector const & other) const;
	vector operator-(vector const & other) const;
	double operator*(vector const & other) const;
	double operator^(vector const & other) const;

	vector operator-() const;
	vector operator+() const;

	vector operator*(double num) const;
	friend vector operator*(double num, vector const & vect);
	vector operator/(double num) const;

	friend std::istream & operator >> (std::istream & is, vector & vect);
	friend std::ostream & operator << (std::ostream & os, vector const & vect);

	double get_x();
	double get_y();

	///destructor:
	~vector();
private:
	double x;
	double y;
};

std::istream & operator >> (std::istream & is, vector & vect);
std::ostream & operator << (std::ostream & os, vector const & vect);