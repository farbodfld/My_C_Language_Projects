#include <iostream>

int main() {
    char input[4], num;

    for (char &i : input) {
        std::cin >> num;
        i = num;
    }

    std::cout << "saal:" << input[0] << input[1];
    std::cout << std::endl;
    std::cout << "maah:" << input[2] << input[3];

    return 0;
}