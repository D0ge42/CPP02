#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>
#include <cstdlib>
#include <sys/types.h>

static bool check_all_segments(float x1, float y1, float x2, float y2, float x3, float y3, float X, float Y);
static bool is_point_on_segment(float x1, float y1, float x2, float y2,float X, float Y);
static float calculate_area(float x1, float y1, float x2, float y2, float x3, float y3);

/* Main bsp function.
 * Parameters: 4 Point objects.
 * Return value -> bool indicating whether the given P point is inside
 * outside or lies on segments/vertexes of the triangle.
 * Description: From the Point items, we retrieve the Fixed Class Object and from
 * each one of them we use the .toFloat() method.
 * This way we're able to conver the fixed point value to a float.
 * Once we've our floats, we can calculate the area of the triangles.
 * There are 4 triangles cause we can also delimit triangles made with the P point,
 * namely the Point to check.
 * The sum of the "secondary triangles should return the area of the main one.
 * If thats the case it means the point is inside the main triangle.
 * Now all we've to do is check if the given Point is on a vertex or segment of the
 * triangle."*/

bool bsp(Point const P1, Point const  P2, Point const P3, Point const P)
{
  float x1 = P1.getX().toFloat();
  float y1 = P1.getY().toFloat();
  float x2 = P2.getX().toFloat();
  float y2 = P2.getY().toFloat();
  float x3 = P3.getX().toFloat();
  float y3 = P3.getY().toFloat();
  float X = P.getX().toFloat();
  float Y = P.getY().toFloat();

  float A = calculate_area(x1, y1, x2, y2, x3, y3);
  float A1 = calculate_area(X, Y, x1, y1, x2, y2);
  float A2 = calculate_area(X, Y, x2, y2, x3, y3);
  float A3 = calculate_area(X, Y, x1, y1, x3, y3);

  if (A == A1 + A2 + A3)
  {
    if (check_all_segments(x1, y1, x2, y2, x3,  y3,  X,  Y) == true)
    {
      std::cout << "Point is either on a segment or vertex\n\n";
      return false;
    }
    else
      return true;
  }
  return false;
}

/* Params: floats indicating point coordinates.
 * Return: float, indicating area of the triangle.
 * Formula that calculates the area of a triangle.
 * If its negative it makes a XOR on the most significant bit, which indicates the sign.
 * By XOR'ing the most significant bit we're actually changing the sign of the number.
 * This way we can retrieve the absolute value and divide it by 2, to get the area. */

static float calculate_area(float x1, float y1, float x2, float y2, float x3, float y3)
{
  float area;
  area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
  if (area < 0)
    *(u_int32_t *)&area ^= (1 << 31);
  return area/2;
}

/* Params: floats indicating point coordinates.
 * Return: bool, True or false depending if a point is found on vertex or segment.
 * Description: Looks if the given X/Y point lies either on the segments or vertexes
 * of the triangle.*/

static bool check_all_segments(float x1, float y1, float x2, float y2, float x3, float y3, float X, float Y)
{
  int conditions = 0;
  if (is_point_on_segment(x1, y1, x2, y2, X, Y) == true)
    conditions++;
  if (is_point_on_segment(x2, y2, x3, y3, X, Y) == true)
    conditions++;
  if (is_point_on_segment(x3, y3, x1, y1, X, Y) == true)
    conditions++;
  if (conditions >= 1)
    return true;
  return false;
}

/* Params: floats indicating point coordinates.
 * Returns true or false, depending if a point is found on vertex or segment.
 * Description: it first check if the coordinates of the point we're checking
 * fall between the segment endpoints.
 * Then thanks to a crossproduct (made to avoid division by 0), we check
 * if the given point as the same slope of the triangle segments.
 * If so it means it lies on the same segment.
 * */

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
