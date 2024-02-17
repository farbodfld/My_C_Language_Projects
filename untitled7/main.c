#include <stdio.h>
#include <math.h>

int main() {
    int a,tedadezojha=0,b=0,tedadefardha=0,tavanedah=0;
    scanf("%d",&a);
    while(a>0){
        int baghimande = a%10;
        if(baghimande%2 == 0)
            b += baghimande * pow(10, tedadezojha++);

        if(baghimande%2 == 1)
            tedadefardha += 1;
        tavanedah++;
        a /= 10;
    }
    if(tedadefardha == tavanedah && b == 0 )
        printf("All digits were deleted");
    else
        printf("%d",b);
    return 0;
}