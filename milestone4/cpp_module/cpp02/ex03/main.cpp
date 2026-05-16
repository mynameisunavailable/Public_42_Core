#include "bsp.hpp"
#include <iostream>

int main( void ) {
	Point	a(0, 0);
	Point	b(10, 12);
	Point	c(8, -8);
	Point	point(0, 0);

	// on vertice a = false
	std::cout << "status point p inside triangle: " << bsp(a, b, c, point) << std::endl;
	
	Point	a1(0, 0);
	Point	b1(10, 12);
	Point	c1(8, -8);
	Point	point1(2, 2);

	// inside triangle = true
	std::cout << "status point p inside triangle: " << bsp(a1, b1, c1, point1) << std::endl;
	
	Point	a2(0, 0);
	Point	b2(10, 12);
	Point	c2(8, -8);
	Point	point2(-2, -2);

	// outside triangle = false
	std::cout << "status point p inside triangle: " << bsp(a2, b2, c2, point2) << std::endl;
	
	return 0;
}