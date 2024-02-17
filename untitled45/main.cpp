#include <iostream>
#include <math.h>
using namespace std;

#define N 10

// tabeyi bara mohasebe A* matris
int ** A_setare(int **mat,  int p, int q, int n)
{
    int** temp;
    int i = 0, j = 0;
    temp = new int*[n - 1];
    for (int k = 0; k < n - 1; ++k) {
        temp[k] = new int[n - 1];
    }

    // matrix ro dorost mikonim
    for (int radif = 0; radif < n; radif++)
    {
        for (int sootoon = 0; sootoon < n; sootoon++)
        {
            //element hayi ke too ye radif o stoon nistanro too matrix temp mirizim
            if (radif != p && sootoon != q)
            {
                temp[i][j++] = mat[radif][sootoon];

                // radif va stoon ro afzayesh midim
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return temp;
}

/* ba estefade az A* determinal ro hesab mikonim. */
int determinantOfMatrix(int **mat, int n)
{
    int B = 0;

    // agar matris tak element bood
    if (n == 1)
        return mat[0][0];

    int **temp; // baraye sort matrix

    int sign = 1;


    for (int f = 0; f < n; f++)
    {
        // daryafte A*
        temp=A_setare(mat, 0, f, n);
        B += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);
        for (int i = 0; i < n - 1 ; ++i) {
            delete[] temp[i];
        }
        delete[] temp;


        sign = -sign;
    }

    return B;
}


int main()
{
    int n;
    cin>>n;
    //int a[10][10];
    int** a;
    a = new int*[n];
    for (int k = 0; k < n; ++k) {
        a[k] = new int[n];

    }

    for (int i = 0; i <n ; ++i)
    {
        for (int j = 0; j < n ; ++j)
        {
            cin>>a[i][j];

        }

    }
    cout<<determinantOfMatrix(a, n);
    for (int l = 0; l < n; ++l) {
        delete[] a[l];
    }
    delete[]  a;


    return 0;
}
