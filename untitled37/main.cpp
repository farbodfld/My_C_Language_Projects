#include <iostream>
//# define n
using namespace std;
void taranahade(int a[50][50] , int b [50][50] , int r , int c)
{
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            b[j][i] = a[i][j];
}
void sakhtmatris(int a[50][50] , int r , int c)
{
    for (int i = 0; i < r ; ++i)
   // {
        for (int j = 0; j < c ; ++j)
        //{
            cin>>a[i][j];

       // }

    //}
}
void zarbmatrisha(int a[50][50] , int b[50][50] , int c[50][50] , int r1 , int c1 , int r2 , int c2)
{
    for(int i = 0; i < r1; i++)
        for( int j = 0; j < c2; j++)
            for(int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
}
/*void printMatrix(int matrix[50][50],int r,int c)
{
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}*/
int main()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1 != c2) {
        cout << "Undefined" << endl;
        return 0;
    }
    int a[50][50];
    int b[50][50];
    sakhtmatris(a, r1, c1);
    sakhtmatris(b, r2, c2);
    int at[50][50];
    int bt[50][50];
    taranahade(a, at, r1, c1);
    taranahade(b, bt, r2, c2);
    int c[50][50];
    zarbmatrisha(at , bt , c , r1 , c1 , r2 , c2);
   // printMatrix(c,c1,r2);
    for (int i = 0; i < c1 ; ++i)
    {
        for (int j = 0; j < r2 ; ++j)
        {
            cout<<c[i][j]<<" ";

        }
        cout<<endl;
    }
    return 0;
}