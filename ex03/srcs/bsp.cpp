#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>
#include <cstdlib>
#include <sys/types.h>

bool bsp(Point const a, Point const b, Point const c, Point const point);
static bool check_all_segments(float x1, float y1, float x2, float y2, float x3, float y3, float X, float Y);
static bool is_point_on_segment(float x1, float y1, float x2, float y2,float X, float Y);
static float calculate_area(float x1, float y1, float x2, float y2, float x3, float y3);

bool bsp(float x1, float y1, float x2, float y2, float x3, float y3, float X, float Y)
{
  float A = calculate_area(x1, y1, x2, y2, x3, y3);
  float A1 = calculate_area(X, Y, x1, y1, x2, y2);
  float A2 = calculate_area(X, Y, x2, y2, x3, y3);
  float A3 = calculate_area(X, Y, x1, y1, x3, y3);

  if (A == A1 + A2 + A3)
  {
    if (check_all_segments(x1, y1, x2, y2, x3,  y3,  X,  Y) == true)
    {
      std::cout << "Point is on a segment or vertex\n";
      return false;
    }
    else
      return true;
  }
  return false;
}

static float calculate_area(float x1, float y1, float x2, float y2, float x3, float y3)
{
  float area;
  area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
  if (area < 0)
    *(u_int32_t *)&area ^= (1 << 31);
  return area/2;
}

static bool check_all_segments(float x1, float y1, float x2, float y2, float x3, float y3, float X, float Y)
{
  int conditions = 0;
  if (is_point_on_segment(x1, y1, x2, y2, X, Y) == true)
    conditions++;
  if (is_point_on_segment(x2, y2, x3, y3, X, Y) == true)
    conditions++;
  if (is_point_on_segment(x3, y3, x1, y1, X, Y) == true)
    conditions++;
  printf("Satisfied conditions %i\n", conditions);
  if (conditions >= 1)
    return true;
  return false;
}

static bool is_point_on_segment(float x1, float y1, float x2, float y2,float X, float Y)
{
  int conditions = 0;
  if ((X >= std::min(x1,x2) && X <= std::max(x1,x2)) && (Y >= std::min(y1,y2) && Y <= std::max(y1,y2)))
    conditions++;
  if (((X - x1) * (y2 - y1)) == ((Y - y1) * (x2 - x1)))
    conditions++;
  if (conditions == 2)
    return true;
  return false;
}
