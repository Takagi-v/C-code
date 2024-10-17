#include <iostream>
#include "polynomial.h"
using namespace std;
int main()
{
  Type stop_flag;
  getStop(stop_flag);
  Polynomial<Type> La(stop_flag), Lb(stop_flag), Lc(stop_flag);
  La.getPoly();
  Lb.getPoly();
  Lc.addPoly(La, Lb);
  Lc.display();
  return 0;
}