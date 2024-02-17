#include <iostream>

using namespace std;

int main() {
    int x, y = 3;
    int arr[y];
    for (int i = 0; i < y; ++i) {
        cin >> x;
        arr[i] = x;
    }
    for (int j = 0; j < y; ++j) {
        cout << arr[j];
    }
    return 0;
}