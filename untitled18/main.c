#include <stdio.h>
int olgoo(int a)
{
    int s = 0;
    while(a > 0)
    {
       if(a & 1 && (a & 1<<1) == 0 && a & 1<<2)
           s++;
       a = a>>1;
    }
    return s;
}

int main() {
    int a;
    scanf("%d",&a);
    printf("%d",olgoo(a));
    return 0;
}