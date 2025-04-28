#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>
#include <cstdlib>
#include <sys/types.h>

Point::Point():_x(0),_y(0)
{}

Point::Point(const float num1, const float num2):_x(num1),_y(num2)
{}

Point::~Point()
{}

const Fixed &Point::getX(void) const
{
  return this->_x;
}

const Fixed &Point::getY(void) const
{
  return this->_y;
}
