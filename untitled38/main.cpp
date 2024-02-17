#include <iostream>
using namespace std;
void taranahade(int a[50][50],  int b[50][50] , int r, int c)
{
    for (int i = 0; i <r; ++i)
        for (int j = 0; j < c; ++j)
            b[j][i] = a[i][j];
}
void zarbmatrisha(int a1[50][50], int b1[50][50], int c[50][50] , int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k)
                c[i][j] += a1[i][k] * b1[k][j];

        }
    }
}
void sakhtmatrisha(int MATRIS[50][50], int r, int c)
{
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin >> MATRIS[i][j];
}
int main() {
    int R1 , c1 , R2 , c2 , m , c;
    cin >> R1 >> c1 >> R2 >> c2;
    if (R1 != c2){
        cout << "Undefined" << endl;

    }
    else
        {
        int a[50][50];
        int b[50][50];
        sakhtmatrisha(a, R1, c1);
        sakhtmatrisha(b, R2, c2);
        int aT[50][50];
        int bT[50][50];
        taranahade(a, aT, R1, c1);
        taranahade(b, bT, R2, c2);
        int jadid[50][50];
        zarbmatrisha(aT, bT, jadid , c1, R1, c2, R2);
        for (int i = 0; i < c1; ++i) {
            for (int j = 0; j < R2; ++j) {
                cout << jadid[i][j] << " ";

            }
            cout << endl;
        }
    }
    return 0;
}


