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

Point Point::getX(void)
{
  return this->_x;
}

Point Point::getY(void)
{
  return this->_y;
}
