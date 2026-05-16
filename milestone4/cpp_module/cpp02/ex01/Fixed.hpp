#ifndef FIXED_HPP
#define  FIXED_HPP

#include <iostream>
#include <cmath>

// #define FLOAT_SIGNED_BITS 1
// #define FLOAT_EXPONENT_BITS 8
// #define FLOAT_MANTISSA_BITS 23

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& item);
		~Fixed(void);

		Fixed& operator= (const Fixed& item);

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
