#include "../includes/Fixed.hpp"
#include <cmath>

/*------------------PRE/POST INCREMENTS OP--------------------*/

/* -- Main difference between the two is that in the post increment
 * operator takes a dummy int as parameter since both of them use either
 * -- or ++.
 *  Also in the post increment operator we'll return an instance of the same
 *  object before the incremenet. Thats because when we do something like
 *  j + i++ where j == 1, and i == 0 --> result is 1 + 0 and not 1 + 1.
 *  */

Fixed Fixed::operator++()
{
  ++_fpValue;
  return *this;
}

Fixed Fixed::operator--()
{
  --_fpValue;
  return *this;
}

Fixed Fixed::operator++(int)
{
  Fixed tmp = *this;
  _fpValue++;
  return tmp;
}

Fixed Fixed::operator--(int )
{
  Fixed tmp = *this;
  _fpValue--;
  return tmp;
}

