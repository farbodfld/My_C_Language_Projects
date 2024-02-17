#include <stdio.h>

int main() {

int main() {
    int n;
    scanf("%d",&n);
    if (n%2 == 0)
    {
        for (int i =0 ;i < n;i++)
        {
            for (int j = 0; j < n-i; ++j)
                printf("*");
            for (int k = 0; k < i; ++k)
                printf("  ");
            for (int j = 0; j < n-i; ++j)
                printf("*");
            printf("\n");
        }
        for (int i = n-2 ;i >= 0;i--)
        {
            for (int j = 0; j < n-i; ++j)
                printf("*");
            for (int k = 0; k < i; ++k)
                printf("  ");
            for (int j = 0; j < n-i; ++j)
                printf("*");
            printf("\n");
        }
    } else{
        for (int i =0 ;i < n;i++)
        {
            for (int j = 0; j < n-i; ++j)
                printf("*");
            for (int k = 0; k < i; ++k)
                printf("  ");
            for (int j = 0; j < n-i; ++j)
                printf("*");
            printf("\n");
        }
        for (int i = n-1 ;i >= 0;i--) {
            for (int j = 0; j < n - i; ++j)
                printf("*");
            for (int k = 0; k < i; ++k)
                printf("  ");
            for (int j = 0; j < n - i; ++j)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}