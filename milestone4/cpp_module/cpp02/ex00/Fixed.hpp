#ifndef FIXED_HPP
#define  FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& item);
		Fixed& operator= (const Fixed& item);
		
		~Fixed(void);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
	private:
		int		_val;
		static const int _fraBits = 8;
};

#endif