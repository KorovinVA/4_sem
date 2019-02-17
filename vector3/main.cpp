#include "vector.h"
#include <conio.h>
#include <iostream>

int main() {
	vector3 c;
	vector3 a(5, 5, 5);

	std::cin >> c;
	std::cout << c << std::endl;
	std::cout << "input-output has been checked" << std::endl << std::endl;

	std::cout << "+(5,5,5): " << a + c << std::endl;
	c += c;
	std::cout << "+=(vector += vector): " << c << std::endl;
	std::cout << "plus has been checked" << std::endl << std::endl;

	std::cout << "vector-(5,5,5):" << c - a << std::endl;
	std::cout << "(5,5,5) - vector:" << a - c << std::endl;
	c -= c;
	std::cout << "-=(vector -= vector): " << c << std::endl;
	std::cout << "unary_minus(5,5,5): " << -a << std::endl;
	std::cout << "minus has been checked" << std::endl << std::endl;

	c = a;
	std::cout << "squal[(5,5,5) * (5,5,5)]:" << a * c << std::endl;
	vector3 i(1, 0, 0);
	vector3 j(0, 1, 0);
	vector3 k = i ^ j;
	std::cout << "vec[(1,0,0) * (0,1,0)]: " << k << std::endl;
	std::cout << "(5,5,5) * 2: " << a * 2 << std::endl;
	std::cout << "2 * (5,5,5): " << 2 * a << std::endl;
	std::cout << "(5,5,5) /  5: " << a / 5 << std::endl;
	std::cout << "multiplication and division have been checked" << std::endl << std::endl;

	std::cout << "norm(1,0,0): " << i.norm() << std::endl;
	std::cout << "norm(5,5,5): " << a.norm() << std::endl;
	std::cout << "len(1,0,0): " << i.len() << std::endl;
	std::cout << "len(5,5,5): " << a.len() << std::endl;
	std::cout << "len and norm have been checked" << std::endl << std::endl;
	_getch();
}
