#include <stdio.h>

int main() {
        int a,b,result;
        scanf("%d %d",&a,&b);
        result = a;
    do{
            result += a/b;
            a = (a%b) + a/b;
        }while(a >= b);
        printf("%d",result);
        return 0;
    }
