#include "../includes/Fixed.hpp"
#include <cmath>

/*----------------------OPERATORS-----------------------------*/

float Fixed::operator+(Fixed ref)const
{
  return (this->toFloat() + ref.toFloat());
}

float Fixed::operator-(Fixed ref)const
{
  return (this->toFloat() - ref.toFloat());
}

float Fixed::operator/(Fixed ref)const
{
  return (this->toFloat() / ref.toFloat());
}

float Fixed::operator*(Fixed ref)const
{
  return (this->toFloat() * ref.toFloat());
}

