#include <iostream>

using namespace std;

bool Find_TumNumber(int number);

int main() {
    /** Q 47 **/
    /*int number, reversedNumber = 0;
    cin >> number;

    while (number % 10 != 0){
        reversedNumber = (reversedNumber * 10) + number % 10;
        number /= 10;
    }

    cout << reversedNumber << endl;*/

    /** Q 11 **/
    /*int n, s = 0, w = 0;
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        if (i % 2 != 0) {
            s += i;
            w++;
            cout << i << endl;
        }
    }

    cout << s << endl;
    cout << w << endl;*/

    /** Q 21 **/
    cout << "Start" << endl;
    int N;
    cout << "What is N : " << endl;
    cin >> N;

    for (int i = 2; i <= N; ++i) {
        if (Find_TumNumber(i)){
            cout << i << " ";
        }
    }
    return 0;
}

bool Find_TumNumber(int number) {
    int Sum = 0;

    for (int j = 1; j <= number; ++j) {
        if (number % j == 0 && j < number) {
            Sum += j;
        }
    }

    return Sum == number;
}