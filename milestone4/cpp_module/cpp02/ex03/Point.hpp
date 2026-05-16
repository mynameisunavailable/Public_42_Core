#ifndef Point_HPP
#define  Point_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		Point(const Point& src);
		Point&	operator=	(const Point& src);
		~Point(void);

		Point operator- (const Point& item) const;

		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

#endif
