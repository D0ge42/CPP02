#include "../includes/Fixed.hpp"
#include <cmath>

/*Comparison operators. They all return a bool
 * indicating wheter the comparison was True or False*/

bool Fixed::operator!=(const Fixed &ref) const
{
  return (this->toFloat() != ref.toFloat());
}

bool Fixed::operator==(const Fixed &ref) const
{
  return (this->toFloat() == ref.toFloat());
}

bool Fixed::operator>=(const Fixed &ref) const
{
  return (this->toFloat() >= ref.toFloat());
}

bool Fixed::operator<=(const Fixed &ref) const
{
  return (this->toFloat() <= ref.toFloat());
}

bool Fixed::operator<(const Fixed &ref) const
{
  return (this->toFloat() < ref.toFloat());
}

bool Fixed::operator>(const Fixed &ref) const
{
  return (this->toFloat() > ref.toFloat());
}

