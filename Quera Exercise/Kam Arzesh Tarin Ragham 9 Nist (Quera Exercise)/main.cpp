#include <iostream>

using namespace std;

int Factorial(int n) {
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

int Founding_Mod(int n_factorial) {
    int result = 0, mod = 10, flag = 0;

    while (flag == 0) {
        if (n_factorial % mod == 0) {
            n_factorial /= 10;
        } else {
            result = n_factorial % mod;
            flag = 1;
        }
    }

    return result;
}

int main() {
    int n, factorial;

    cin >> n;
    factorial = Factorial(n);

    cout << Founding_Mod(factorial);
    return 0;
}