#include<iostream>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int _hash_(int a, int b)
{
    return ((a % 10) * 10) + (b % 10);
}

/************Your Implementations***************/

int** func(int rows,int cols, int** A, int** B, int (*f)(int , int))
{
    int** a = new int*[rows];
    for (int i = 0; i < rows ; ++i)
    {
        a[i]=new int [cols];
    }
    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i <cols ; ++i) {
            a[j][i]=(*f)(A[j][i],B[j][i]);
        }
    }
    return a;
}

void print(int rows ,int cols , int** b)
{
    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i <cols ; ++i) {
            cout<<b[j][i]<<" ";
        }
        cout<<endl;
    }
}

/***********************************************/

int main()
{
    int **A = new int*[3];
    for (int i = 0; i < 3; i++)
    {
        A[i] = new int[4];
        for(int j = 0; j < 4; j++)
            A[i][j] = (4 * i) + j + 1;
    }

    int **B = new int*[3];
    for (int i = 0; i < 3; i++)
    {
        B[i] = new int[4];
        for(int j = 0; j < 4; j++)
            B[i][j] = i + j;
    }

    print(3, 4, A);
    /* 1 2 3 4
       5 6 7 8
       9 10 11 12
    */

    print(3, 4, B);
    /* 0 1 2 3
       1 2 3 4
       2 3 4 5
    */

    int **C = func(3, 4, A, B, add);
    print(3, 4, C);
    /* 1 3 5 7
       6 8 10 12
       11 13 15 17
    */

    int **D = func(3, 4, A, B, _hash_);
    print(3, 4, D);
    /* 10 21 32 43
       51 62 73 84
       92 3 14 25
    */
    return 0;
}