#include <iostream>

using namespace std;

int main() {
    string S, input;
    cin >> S;

    int n, counter = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> input;
        if (input == S)
            counter++;
        if (input.find(S))
            counter++;
    }

    cout << counter;
    return 0;
}
