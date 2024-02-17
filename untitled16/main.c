#include <stdio.h>
int TARA(int n ,int v)
{
    int hazine= 0,benzin = 0 ;
    if(n > v)
        benzin += v;
    else
        benzin += (n-1);
    hazine = benzin;
    for(int i = 2 ; i<=n ; i++)
    {
        --benzin;
        if(i <= (n-v)) {
            ++benzin;
            hazine += i;
        }
        if(i%3 == 0)
            ++hazine;
    }
    return hazine;
}

int main() {
    int n,v;
    scanf("%d %d",&n,&v);
   printf("%d",TARA(n,v));

    return 0;
}