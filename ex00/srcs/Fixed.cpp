#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed():_fpValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*Copy constructor method.
 * It will create a new class object out of an existing one.
 * A reference has to be passed, because passing a value to it
 * would result in infinite recursion. This would result
 * in a stack overflow.*/

Fixed::Fixed(Fixed const &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

/* By default a copy assignment operator is built by
 * the compiler so it won't be needed to create one, unless
 * we would like to assign a particular behaviour.
 * Checking for (this != &other) is not really needed since
 * the compiler will prompt an error when we do so.
*/

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &other)
	    this->_fpValue = other.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fpValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fpValue = raw;
}

