#ifndef FIXED_HPP
#define  FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& item);
		~Fixed(void);

		Fixed&	operator=	(const Fixed& item);
		bool	operator>	(const Fixed& item) const;
		bool	operator<	(const Fixed& item) const;
		bool	operator>=	(const Fixed& item) const;
		bool	operator<=	(const Fixed& item) const;
		bool	operator==	(const Fixed& item) const;
		bool	operator!=	(const Fixed& item) const;
		Fixed	operator+	(const Fixed& item) const;
		Fixed	operator-	(const Fixed& item) const;
		Fixed	operator*	(const Fixed& item) const;
		Fixed	operator/	(const Fixed& item) const;
		Fixed&	operator++	(void);
		Fixed	operator++	(int);
		Fixed&	operator--	(void);
		Fixed	operator--	(int);
		
		static 			Fixed&	min(Fixed& a, Fixed& b);
		static const	Fixed&	min(const Fixed& a, const Fixed& b);
		static 			Fixed&	max(Fixed& a, Fixed& b);
		static const	Fixed&	max(const Fixed& a, const Fixed& b);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat(void) const;
		int		toInt(void) const;
		
	private:
		int		_val;
		static const int _fraBits = 8;
};

std::ostream&	operator<< (std::ostream& output, const Fixed& item);

#endif

/* 
Add public member functions to your class to overload the following operators:
• The 6 comparison operators: >, <, >=, <=, ==, and !=.
• The 4 arithmetic operators: +, -, *, and /.
• The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, which will increase or decrease the fixed-point value by
the smallest representable ϵ, such that 1 + ϵ > 1.
Add these four public overloaded member functions to your class:
• A static member function min that takes two references to fixed-point numbers as
parameters, and returns a reference to the smallest one.
• A static member function min that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the smallest one.
• A static member function max that takes two references to fixed-point numbers as
parameters, and returns a reference to the greatest one.
• A static member function max that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the greatest one.
 */