#include <iostream>
#include <math.h>

double delta(double a, double b, double c) {
    return ((b * b) - (4 * a * c));
}

void formula(double b, double a, double delta) {
    double multiple_a = a + a;
    double result[2];
    double x1 = (-b + sqrt(delta)) / multiple_a;
    double x2 = (-b - sqrt(delta)) / multiple_a;
    result[0] = x1;
    result[1] = x2;
    std::cout << x1 << " and " << x2;
}

int main() {
    std::cout << "Quadratic Equation form is something like below\nax^2+bx+c=0" << std::endl;
    std::cout << "enter value of a: ";
    double a;
    std::cin >> a;
    std::cout << "enter value of b: ";
    double b;
    std::cin >> b;
    std::cout << "enter value of c: ";
    double c;
    std::cin >> c;
    std::cout << "your equation is: " << a << "x^2+" << b << "x+" << c << "=0" << std::endl;
    std::cout << "answer is: ";
    double deltaNUM = delta(a, b, c);
    if (deltaNUM < 0)
        std::cout << "equation dose not have any answer because the value of delta is less than zero." << std::endl;
    else
        formula(b, a, deltaNUM);
    return 0;
}