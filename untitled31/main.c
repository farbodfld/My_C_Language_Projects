#include <stdio.h>

int inteligencebaghimande(int a, int b, int C)
{
    // halat paye
    if (a == 0)
        return 0;
    if(C == 1)
        return 0;
    if (b == 0)
        return 1;

    // halat dige b
    long x;
    if (b % 2 == 0) {
        x = inteligencebaghimande(a, b / 2, C);
        x = (x * x) % C;
    }


    else {
        x = a % C;
        x = (x * inteligencebaghimande(a, b - 1, C) % C) % C;
    }

    return (int)((x + C) % C);
}


int main()
{
    int a , b , C ;
    scanf("%d %d %d",&a,&b,&C);
    printf("%d",inteligencebaghimande(a, b, C));
    return 0;
}
