#include "../includes/Fixed.hpp"
#include <cmath>

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
  if (a._fpValue > b._fpValue)
    return b;
  return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{

  if (a._fpValue < b._fpValue)
    return b;
  return a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
  if (a._fpValue > b._fpValue)
    return b;
  return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
  if (a._fpValue < b._fpValue)
    return b;
  return a;
}

