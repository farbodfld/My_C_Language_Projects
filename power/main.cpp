#include <iostream>

int main() {
    int n, num = 2, result;
    std::cin >> n;
    while (num < n) {
        result = num * 2;
        num = result;
        if (result > n)
            std::cout << result << std::endl;
    }
    return 0;
}