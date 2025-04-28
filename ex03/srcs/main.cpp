#include "Point.hpp"
#include "bsp.h"
#include <cmath>
#include <sys/types.h>

static void check(const Point p1, const Point p2, const Point p3, const Point P);

int main()
{

  std::cout << '\n';
  std::cout << "---TEST: POINT IS INSIDE TRIANGLE ---" << "✅" << '\n';
  const Point p1(-3,0);
  const Point p2(-7,0);
  const Point p3(-5,-4);
  const Point P(-6,-1);
  check(p1,p2,p3,P);
  std::cout << "--------------------------------------" << "\n\n";

  std::cout << "---TEST: POINT IS OUTSIDE TRIANGLE ---" << "❌" << '\n';
  const Point p4(-3,0);
  const Point p5(-7,0);
  const Point p6(-5,-4);
  const Point P1(-6,1);
  check(p4,p5,p6,P1);
  std::cout << "--------------------------------------" << "\n\n";

  std::cout << "---TEST: POINT LIES ON A VERTEX ------" << "❌" << '\n';
  const Point p7(-3,0);
  const Point p8(-7,0);
  const Point p9(-5,-4);
  const Point P2(-7,0);
  check(p7,p8,p9,P2);
  std::cout << "--------------------------------------" << "\n\n";

  std::cout << "---TEST: POINT LIES ON A SEGMENT------" << "❌" << '\n';
  const Point pA(-3,0);
  const Point pB(-7,0);
  const Point pC(-5,-4);
  const Point P3(-4,0);
  check(pA,pB,pC,P3);
  std::cout << "--------------------------------------" << "\n";
}

static void check(const Point p1, const Point p2, const Point p3, const Point P)
{
  if (bsp(p1,p2,p3,P))
    std::cout << "Its inside \n";
  else
    std::cout << "Not inside \n";
}
