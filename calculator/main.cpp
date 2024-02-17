#include <iostream>

double Sum(double num1, double num2);

double Subtraction(double num1, double num2);

double Multiple(double num1, double num2);

double Division(double num1, double num2);

using namespace std;

int main() {
    double num1, num2;
    int entry;

    cout << "************MENU************" << endl << "1) Sum\n2) Subtraction\n3) Multiple\n4) Division\n5) Exit\n";

    while (true) {
        cout << "enter your operator: ";
        cin >> entry;
        switch (entry) {
            case 1:
                cout << "please enter your numbers:";
                cin >> num1 >> num2;
                cout << Sum(num1, num2) << endl;
                break;
            case 2:
                cout << "please enter your numbers:";
                cin >> num1 >> num2;
                cout << Subtraction(num1, num2) << endl;
                break;
            case 3:
                cout << "please enter your numbers:";
                cin >> num1 >> num2;
                cout << Multiple(num1, num2) << endl;
                break;
            case 4:
                cout << "please enter your numbers:";
                cin >> num1 >> num2;
                cout << Division(num1, num2) << endl;
                break;
            case 5:
                break;
            default:
                cout << "entry request is not valid.";
        }
        if (entry == 5)
            break;
    }

    return 0;
}

double Division(double num1, double num2) {
    if (num2 == 0)
        cout << "divide by zero is not required";
    else
        return num1 / num2;
}

double Multiple(double num1, double num2) {
    return num1 * num2;
}

double Subtraction(double num1, double num2) {
    return num1 - num2;
}

double Sum(double num1, double num2) {
    return num1 + num2;
}
