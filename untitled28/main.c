#include <stdio.h>
#include <math.h>
int donbale(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n % 2 == 0)
        return 4 * donbale(n/2);
    else
        return 4 * donbale(n/2) + 1;

}

int main() {
    int n , i=0;
    scanf("%d",&n);
    while(i < n )
    {
        printf("%d ",donbale(i));
        i++;
    }
    return 0;
}