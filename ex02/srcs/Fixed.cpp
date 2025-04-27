#include "../includes/Fixed.hpp"
#include <cmath>

Fixed::Fixed():_fpValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

/*Copy constructor method.
 * It will create a new class object out of an existing one.
 * A reference has to be passed, because passing a value to it
 * would result in infinite recursion. This would result
 * in a stack overflow.*/

Fixed::Fixed(Fixed const &ref)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::Fixed(const int num)
{
  // std::cout << "Int constructor called" << std::endl;
  // this->_fpValue = num * pow(2,_fract_bits);
  this->_fpValue = num << this->_fract_bits;
}

/*To convert from floating-point to fixed-point, we follow this algorithm:

1) Calculate x = floating_input * 2^(fractional_bits)
2) Round x to the nearest whole number (e.g. round(x))
3) Store the rounded x in an integer container */

Fixed::Fixed(const float num)
{
  // std::cout << "Float constructor called" << std::endl;
  this->_fpValue = roundf(num * (1 << this->_fract_bits));
}

/*------------------Getters/Setters-------------------------*/

int Fixed::getRawBits() const
{
	return this->_fpValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fpValue = raw;
}

