#include <iostream>
using namespace std;
int main() {
    int R1 ,c1 , R2 ,c2;
    cin >> R1 >> c1 >> R2 >> c2;
    int a[50][50] , b[50][50],aT[50][50],bT[50][50],c[50][50];

    // vorudi migirim
    for (int i = 0; i < R1; ++i)
    {
        for (int j = 0; j < c1; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < R2; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            cin >> b[i][j];
        }
    }

    //hala taranehado dorost konim
    for (int i = 0; i < R1; ++i)
    {
        for (int j = 0; j < c1; ++j)
        {
            aT[j][i] = a[i][j];
        }
    }

    for (int i = 0; i < R2; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            bT[j][i] = b[i][j];
        }
    }


    // hala zarb konim 2 ta taranehade ro
    for (int i = 0; i < c1; ++i)
    {
        for (int j = 0; j < R2; ++j)
        {
            int sum = 0;
            for (int k = 0; k < R1; ++k)
                sum += aT[i][k] * bT[k][j];
            c[i][j] = sum;
        }
    }
    // hala begim age natunesti zarb koni begu nemishe
    if (R1 != c2){
        cout << "Undefined" << endl;
        return 0;
    }

    //agaram tunest khob chap esh kone

    for (int i = 0; i < c1; ++i) {
        for (int j = 0; j < R2; ++j) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}