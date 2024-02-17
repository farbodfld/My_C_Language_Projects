#include <stdio.h>

int main() {
    int a,b;
    scanf("%d %d" , &a ,&b);
    int tedadeAvvalha = 0;
    for (int j = a; j <= b; ++j) {
        int n = 0;
        for (int k = 2; k < j; ++k)
            if (j % k == 0)
                n++;

        if (n == 0 && j >= 2)
        {
            tedadeAvvalha++;
            if (tedadeAvvalha == 1)
                printf("%d",j);
            else printf(",%d",j);
        }
    }
    return 0;
}