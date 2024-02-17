#include<iostream>

using namespace std;

int main() {
    int i, j;
    int no = 30, abc;
    abc = no / 4;

    for (i = 1; i <= no / 4; i++) {
        cout << "\t\t";
        for (j = 1; j < abc; j++)
            cout << " ";
        abc--;
        for (j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        cout << "\n";
    }

    abc = no / 3;
    for (i = 3; i <= no / 3; i++) {
        cout << "\t" << "   ";
        for (j = 1; j < abc; j++)
            cout << " ";
        abc--;
        for (j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        cout << "\n";
    }

    abc = no / 2;
    for (i = 4; i <= no / 2; i++) {
        cout << "     ";
        for (j = 1; j < abc; j++)
            cout << " ";
        abc--;
        for (j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        cout << "\n";
    }

    for (i = 0; i < no / 3; i++) {
        cout << "\t\t" << "     ";
        cout << "***";
        cout << "\n";
    }
    //  cout<< "" << "\t*****";//Enter The AnyThing In Place Of ( * ) Like Any Key For Change Pattern
    return 0;
}