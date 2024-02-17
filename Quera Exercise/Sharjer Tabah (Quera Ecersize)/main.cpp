#include <iostream>

using namespace std;

int main() {
    int n, x, y, counter = 0;
    cin >> n >> x >> y;

    int chargePercent[n];
    for (int i = 0; i < n; ++i) {
        cin >> chargePercent[i];
    }

    for (int j = 0; j < n - 1; ++j) {
        chargePercent[j] -= x;
        chargePercent[j + 1] += y;
        if (chargePercent[j + 1] >= 100)
            counter++;
    }

    if (counter == (n - 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}