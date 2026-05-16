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

bool	Fixed::operator>	(const Fixed& item) const
{
	return (this->getRawBits() > item.getRawBits());
}

bool	Fixed::operator<	(const Fixed& item) const
{
	return (this->getRawBits() < item.getRawBits());
}

bool	Fixed::operator>=	(const Fixed& item) const
{
	return (this->getRawBits() >= item.getRawBits());
}

bool	Fixed::operator<=	(const Fixed& item) const
{
	return (this->getRawBits() <= item.getRawBits());
}

bool	Fixed::operator==	(const Fixed& item) const
{
	return (this->getRawBits() == item.getRawBits());
}

bool	Fixed::operator!=	(const Fixed& item) const
{
	return (this->getRawBits() != item.getRawBits());
}

Fixed	Fixed::operator+	(const Fixed& item) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() + item.getRawBits());
	return (res);
}

Fixed	Fixed::operator-	(const Fixed& item) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() - item.getRawBits());
	return (res);
}

Fixed	Fixed::operator*	(const Fixed& item) const
{
	long	tmpa;
	long	tmpb;
	Fixed	res;

	tmpa = (long) this->getRawBits();
	tmpb = (long) item.getRawBits();
	res.setRawBits((int) (tmpa * tmpb / (1 << _fraBits)));
	return (res);
}

Fixed	Fixed::operator/	(const Fixed& item) const
{
	long	tmpa;
	long	tmpb;
	Fixed	res;

	tmpa = (long) this->getRawBits() * (1 << _fraBits);
	tmpb = (long) item.getRawBits();
	res.setRawBits(tmpa / tmpb);
	return (res);
}

Fixed&	Fixed::operator++	(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++	(int)
{
	Fixed	temp = *this;

	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed&	Fixed::operator--	(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--	(int)
{
	Fixed	temp = *this;

	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const	Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const	Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

		
