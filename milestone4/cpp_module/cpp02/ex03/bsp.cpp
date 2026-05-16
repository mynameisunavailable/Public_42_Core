#include "bsp.hpp"

Fixed calcArea2Vec(Point const a, Point const b, Point const c)
{
	Fixed	area;
	Point	vec_ab = a - b;
	Point	vec_ac = a - c;

	area = (vec_ab.getX() * vec_ac.getY()) - (vec_ac.getX() * vec_ab.getY());
	return (area);
}

// Barycentric Coordinate System
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	acArea = calcArea2Vec(a, c, point);
	Fixed	abArea = calcArea2Vec(c, b, point);
	Fixed	bcArea = calcArea2Vec(b, a, point);

	if (acArea < 0 && abArea < 0 && bcArea < 0)
		return (true);
	else if (acArea > 0 && abArea > 0 && bcArea > 0)
		return (true);
	return (false);
}
// Fixed absFixed(Fixed a)
// {
// 	if (a < 0)
// 		return (a * -1);
// 	return (a);
// }

// Fixed calcArea2Vec(Point const a, Point const b, Point const c)
// {
// 	Fixed	area;
// 	Point	vec_ab = a - b;
// 	Point	vec_ac = a - c;

// 	area = (vec_ab.getX() * vec_ac.getY()) - (vec_ac.getX() * vec_ab.getY());
// 	return (absFixed(area));
// }

// // Barycentric Coordinate System
// bool bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	Fixed	totalArea = calcArea2Vec(a, b, c);
// 	Fixed	acArea = calcArea2Vec(a, c, point);
// 	Fixed	abArea = calcArea2Vec(a, b, point);
// 	Fixed	bcArea = calcArea2Vec(b, c, point);

// 	if (totalArea != (acArea + abArea + bcArea))
// 		return (true);
// 	return (false);
// }
// // Barycentric Coordinate System
// bool bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	Fixed	totalArea = calcArea2Vec(a, b, c);
// 	Fixed	acArea = calcArea2Vec(a, c, point);
// 	Fixed	abArea = calcArea2Vec(a, b, point);
// 	Fixed	bcArea = calcArea2Vec(b, c, point);

// 	if (totalArea < (acArea + abArea + bcArea)
// 		|| acArea == 0 || abArea == 0 || bcArea == 0)
// 		return (false);
// 	return (true);
// }