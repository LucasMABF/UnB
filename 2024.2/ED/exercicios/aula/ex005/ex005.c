#include <stdio.h>
#include "ponto.h"

int main(){
  double  c1[3] = {1, 1, 1};
  double c2[3] = {2, 2, 2};
  Point *p1 = new_point(3, c1);
  Point *p2 = new_point(3, c2);

  Point *p3 = add(p1, p2);

  print_point(p3);
  printf("%lf\n", abs_point(p3));

  double c3 = 3;
  Point *p4 = new_point(1, &c3);
  print_point(p4);
  printf("%lf\n", abs_point(p4));

  Point *p5 = mul_scalar(p1, 10);
  print_point(p5);

  return 0;
}

