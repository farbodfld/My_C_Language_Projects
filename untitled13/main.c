#include <stdio.h>
#include <math.h>
int main() {
    int a, n = 10, i = 0;
    scanf("%d",a);
    while(pow(2, n) > a) {
        --n;
    }
    a = pow(2 , n);
    while( i = 0) {
        i++;
        if (i > 2)
            printf("-1");
    }

}
    printf("%d")

    return 0;
}