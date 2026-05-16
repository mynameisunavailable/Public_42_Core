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
		Fixed&	operator=	(const Fixed& item);
		~Fixed(void);

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
		int		getFraBits( void ) const;

		float	toFloat(void) const;
		int		toInt(void) const;
		
	private:
		int		_val;
		static const int _fraBits = 8;
};

std::ostream&	operator<< (std::ostream& output, const Fixed& item);

#endif