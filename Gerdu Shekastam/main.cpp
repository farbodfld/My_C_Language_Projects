#include<bits/stdc++.h>

using namespace std;

int n, x, y;

int main() {
    cin >> n >> x >> y;
    for (int i = 0; i * x <= n; i++) {
        if ((n - i * x) % y == 0) {
            cout << i << ' ' << (n - i * x) / y << '\n';
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;

}