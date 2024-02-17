#include <iostream>

using namespace std;

int fibonacci(int x) {
    if (x <= 1)
        return x;
    return fibonacci(x - 1) + fibonacci(x - 2);
}

void showFIB() {
    for (int i = 0; i < 10; ++i) {
        cout << fibonacci(i) << " ";
    }
}

int main() {
    showFIB();
    return 0;
}