#include "../includes/Fixed.hpp"
#include <cmath>

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

