#include <stdio.h>
#include <math.h>
int main() {
    int x1,y1,r1;
    int x2,y2,r2;
    scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
    double d,w;
    d = fabs(r1 - r2);
    w=pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
    if(w>d)
        printf("0");
    if(w<d && w>0)
        printf("2");
    if(w==d)
        printf("1");
    if(w==0)
        printf("0");

    return 0;
}