#include <stdio.h>
#include <math.h>
int BMM(int a , int b)
{
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    //int c = 0;
    if(a % b == 0)
        return b;
    else
    return BMM(b , a - b);
}

int main() {
    int a , b ; //c = 0;
    scanf("%d %d",&a,&b);
    printf("%d",BMM(a , b));
    return 0;
}