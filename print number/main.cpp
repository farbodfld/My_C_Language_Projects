#include <iostream>

int main() {
    std::string number;
    std::cin >> number;

    for (char digit : number) {
        std::cout << digit << ": ";
        for (int i = 0; i < digit - '0'; ++i) {
            std::cout << digit;
        }
        std::cout << std::endl;
    }
    return 0;
}