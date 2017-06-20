#include <stdio.h>
#include <math.h>

double function_1(double x);
double function_2(double x);
double function_3(double x);


double function_1(double x)
{
  return x;
}

double function_2(double x)
{
  return (x*x - 3*x);
}

double function_3(double x)
{
  return (cos(x) + sin(x));
}

