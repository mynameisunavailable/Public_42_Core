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

int		Fixed::getRawBits( void ) const
{
	print_line("getRawBits member function called");
	return (_val);
}

void	Fixed::setRawBits( int const raw )
{
	_val = raw;
}
