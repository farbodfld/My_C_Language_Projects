#include <stdio.h>
#include <math.h>
int main() {
    long long int n,f=0;
    scanf("%d",&n);
    for (int i = 1; i<=n ; ++i) {
        long long int a =1;
        for(int j = 0 ; j<i ; ++j)
             a *= 10;
        a -= 1;
        if(i%2 == 0)
            a = a * (-1);
        f += a;

    }
    printf("%lld",f);

    return 0;
}