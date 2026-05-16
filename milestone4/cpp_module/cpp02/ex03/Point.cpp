#include "Point.hpp"

// static void	print_line(std::string s)
// {
// 	std::cout << s << std::endl;
// }

Point::Point(void): _x(0), _y(0) {};

Point::Point(const float x, const float y): _x(x), _y(y) {};

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y) {};

Point::Point(const Point& src): _x(src.getX()), _y(src.getY()) {};

Point& Point::operator= (const Point& src)
{
	if (&src != this)
	{
		return (*this);
	}
	return (*this);
}

Point::~Point(void)
{
	// print_line("Point destructor called");
}

Point Point::operator- (const Point& item) const
{
	Fixed	x = this->getX() - item.getX();
	Fixed	y = this->getY() - item.getY();
	return (Point(x, y));
}

Fixed Point::getX(void) const
{
	return (_x);
}

Fixed Point::getY(void) const
{
	return (_y);
}