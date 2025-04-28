#include "Fixed.hpp"
#include "Point.hpp"
#include <bitset>
#include <cmath>
#include <sys/types.h>

int main()
{
  Point p;
  if (is_point_inside(-3,0,-7,0,-5,-4,-6.9,-0.1))
    std::cout << "Its inside \n";
  else
    std::cout << "Not inside \n";
}
