#include <stdio.h>
#include <math.h>
double zavie(int h , int m)
{
   h = m/60 + h;
   h = h%12;
   m = m%60;
    double a =  (11.0/2 * m) - (30.0 * h);
    if(a < 0.0)
       a = a + 360;
    if(a > 180.0)
      a = 360 - a;
    return a;
}

int main() {
    double h , m;
    scanf("%lf %lf",&h,&m);
    printf("%.2lf",zavie(h,m));
    return 0;
}