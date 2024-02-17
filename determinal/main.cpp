#include <iostream>
#include <math.h>
using namespace std;

#define N 10

// tabeyi bara mohasebe A* matris
void A_setare(int** mat[N][N], int** temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;

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
}

/* ba estefade az A* determinal ro hesab mikonim. */
int determinantOfMatrix(int* mat[N][N], int n)
{
    int B = 0;

    // agar matris tak element bood
    if (n == 1)
        return mat[0][0];

    int** temp[N][N]; // baraye sort matrix

    int sign = 1;


    for (int f = 0; f < n; f++)
    {
        // daryafte A*
        A_setare(mat, temp, 0, f, n);
        B += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);

        
        sign = -sign;
    }

    return B;
}


int main()
{
    int n;
    cin>>n;
    int a[10][10];
    for (int i = 0; i <n ; ++i)
    {
        for (int j = 0; j < n ; ++j)
        {
            cin>>a[i][j];

        }

    }
    cout<<determinantOfMatrix(a, n);


    return 0;
}
