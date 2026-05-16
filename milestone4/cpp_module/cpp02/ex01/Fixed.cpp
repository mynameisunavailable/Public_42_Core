#include "Fixed.hpp"

static void	print_line(std::string s)
{
	std::cout << s << std::endl;
}

Fixed::Fixed(void)
{
	print_line("Default constructor called");
	_val = 0;
}

Fixed::Fixed(const int i)
{
	print_line("Int constructor called");
	_val = i << _fraBits;
}

// max value 2 ^ 23
Fixed::Fixed(const float f)
{
	print_line("Float constructor called");
	_val = (int) roundf(f * (1 << _fraBits));
}

Fixed::Fixed(const Fixed& item)
{
	print_line("Copy constructor called");
	this->_val = item.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& item)
{
	print_line("Copy assignment operator called");
	if (&item != this)
		this->_val = item.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	print_line("Destructor called");
}

std::ostream&	operator<< (std::ostream& output, const Fixed& item)
{
	output << item.toFloat();
	return (output);
}

int		Fixed::getRawBits( void ) const
{
	// print_line("getRawBits member function called");
	return (_val);
}

void	Fixed::setRawBits( int const raw )
{
	_val = raw;
}

float	Fixed::toFloat(void) const
{
	return (((float) this->getRawBits()) / (1 << _fraBits));
}

int		Fixed::toInt(void) const
{
	return ((int) (this->getRawBits() / (1 << _fraBits)));
}
