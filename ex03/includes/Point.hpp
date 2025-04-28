#pragma once

#include "Fixed.hpp"
#include <cstdio>

class Point
{
	private:
    Fixed const _x;
    Fixed const _y;

  public:
    Point();
    Point(const float num1, const float num2);
    Point (Fixed const &ref);
    Point &operator=(const Fixed &obj);
    ~Point();

    Point getX();
    Point getY();

    bool is_point_inside(float x1, float y1, float x2, float y2, float x3, float y3, float X, float Y);
 };
