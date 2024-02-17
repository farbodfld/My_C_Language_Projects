#include <stdio.h>

int main() {
    int a,n,max=0;
    scanf("%d",&n);
    while(n>0)
    {
        if (n%10 > max)
            max = n%10;
        n /= 10;
    }
    if(max == 0)
        printf("ZERO");
   if(max == 1)
        printf("ONE");
    if(max == 2)
        printf("TWO");
    if(max == 3)
        printf("THREE");
    if(max == 4)
        printf("FOUR");
    if(max == 5)
        printf("FIVE");
    if(max == 6)
        printf("SIX");
    if(max == 7)
        printf("SEVEN");
    if(max == 8)
        printf("EIGHT");
    if(max == 9)
        printf("NINE");
    return 0;
}