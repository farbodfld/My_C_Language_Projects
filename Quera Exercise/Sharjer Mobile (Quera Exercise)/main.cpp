#include <iostream>

using namespace std;

int TotalAmount(int i){
    int time = 0;

    for (int j = 0; j < i; ++j) {
        time += j + 1;
    }

    return time;
}

/*int Factorial(int n){
    if (n == 0 || n == 1)
        return 1;
    return n * Factorial(n - 1);
}*/

int main() {
    int k;
    cin >> k;

    cout << TotalAmount(k) << endl;
    return 0;
}