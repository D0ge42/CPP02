#include "../includes/Fixed.hpp"
#include <cmath>
#include <ostream>

Fixed& Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy Assignment operator called" << std::endl;
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
