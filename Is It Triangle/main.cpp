#include <iostream>

using namespace std;

int main() {
    int angle1, angle2, angle3, sum;
    cin >> angle1 >> angle2 >> angle3;
    sum = angle1 + angle2 + angle3;

    if (angle1 > 0 && angle2 > 0 && angle3 > 0 && sum == 180)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}