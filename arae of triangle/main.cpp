#include <iostream>
#include <math.h>

int main() {
    double a, b, c;
    printf("Enter sides of a triangle\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    double perimeter = a + b + c;
    perimeter = (a + b + c) / 2; // Semiperimeter

    double area = sqrt(perimeter * (perimeter - a) * (perimeter - b) * (perimeter - c));
    printf("Area of the triangle = %.2lf\n", area);
    return 0;
}