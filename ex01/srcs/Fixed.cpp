#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

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

/* Overload of the insertion operator.
 * It insert a floating-point rapresentation of the fixed-point
 * number into the output stream object passed as parameter.*/

std::ostream& operator<<(std::ostream &os, const Fixed &num)
{
  os << num.toFloat();
  return os;
}

/* By left shifting a num a certain amount of time
 * is the same as multiplying (num * 2 ^_fractal_bits).
 * I've done two different approaches that will return the same result.
*/

Fixed::Fixed(const int num)
{
  std::cout << "Int constructor called" << std::endl;
  // this->_fpValue = num * pow(2,_fract_bits);
  this->_fpValue = num << this->_fract_bits;
}

/*To convert from floating-point to fixed-point, we follow this algorithm:

1) Calculate x = floating_input * 2^(fractional_bits)
2) Round x to the nearest whole number (e.g. round(x))
3) Store the rounded x in an integer container */

Fixed::Fixed(const float num)
{
  std::cout << "Float constructor called" << std::endl;
  this->_fpValue = roundf(num * (1 << this->_fract_bits));
}

/* to convert a floating point number to int
 * we right shift by _fract_bits times.
 * This is equal to dividing the _fpValue to
 * 2 ^_fract_bits*/

int Fixed::toInt(void)const
{
  // return (this->_fpValue / pow(2,this->_fract_bits));
  return (this->_fpValue >> this->_fract_bits);
}

/* to convert from int to float, we have to divide the
 * float value for (2 ^ fract_bits).*/

float Fixed::toFloat(void)const
{
  return ((float)this->_fpValue / (float)(1 << this->_fract_bits));
  // return ((float)this->_fpValue / (float)pow(2,this->_fract_bits));
}


int Fixed::getRawBits() const
{
	return this->_fpValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fpValue = raw;
}

