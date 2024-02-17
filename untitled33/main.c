#include <stdio.h>

int main() {
    char a[50][50];
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf(" %c",&a[j][i]);

        }

    }
    for (int k =  (n - 1) ; k >= 0; --k)
    {
        for (int i = 0; i < k; ++i) {
            printf(" ");
        }
        for (int j = 0; j+k < n; ++j)
        {
            printf("%c ",a[k + j][j]);

        }
        printf("\n");

    }
    for (int k = 1 ; k <n; ++k)
    {
        for (int i = 0; i < k; ++i)
        {
            printf(" ");
        }
        for (int j = 0; j + k < n; ++j)
        {
            printf("%c ", a[j][k + j]);

        }
        printf("\n");
    }


        return 0;
    }
