#include <iostream>

using namespace std;

int main() {
    int n, lightClick, counter = 0;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; ++i) {
        cin >> lightClick;
        data[i] = lightClick;
    }

    for (int j = 0; j < n - 1; ++j) {
        if (data[j] != data[j + 1])
            counter++;
    }

    cout << counter << endl;
    return 0;
}