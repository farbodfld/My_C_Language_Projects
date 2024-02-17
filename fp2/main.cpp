#include<stdio.h>
#include<math.h>
struct noghte
{
    double x,y,z,m;
};
double tool(double , double );
double tool(double f, double b)
{
    return sqrt((f*f)+(b*b));
}
int main()
{
    struct noghte a[10];
    for(int i=0;i<10;i++)
    {
        scanf("%lf %lf %lf %lf",&a[i].x,&a[i].y,&a[i].z,&a[i].m);
    }
    struct noghte c={0, 0, 0, 0};
    for(int i=0;i<10;i++)
    {
        c.m+=a[i].m;
        c.x+=(a[i].x*a[i].m);
        c.y+=(a[i].y*a[i].m);
        c.z+=(a[i].z*a[i].m);
    }
    c.x/=c.m;
    c.y/=c.m;
    c.z/=c.m;
    printf("change x:%lf y:%lf z:%lf\n",-c.x,-c.y,-c.z);
    for(int i=0;i<10;i++)
    {
        a[i].x-=c.x;
        a[i].y-=c.y;
        a[i].z-=c.z;
    }
    double tempx=0,tempy=0,tempz=0;
    for(int i=0;i<10;i++)
    {
        tempz+=(a[i].m*tool(a[i].x,a[i].y));
        tempx+=(a[i].m*tool(a[i].z,a[i].y));
        tempy+=(a[i].m*tool(a[i].x,a[i].z));
    }
    printf("hol x:%lf y:%lf z:%lf\n",tempx,tempy,tempz);
    if(tempy>tempx)
    {
        printf("90 davaran hol z\n");
        for(int i=0;i<10;i++)
        {
            double temp=a[i].y;
            a[i].y=a[i].x;
            a[i].x=(-temp);
        }
        double temp=tempy;
        tempy=tempx;
        tempx=temp;
    }
    if(tempz>tempx)
    {
        printf("90 davaran hol y\n");
        for(int i=0;i<10;i++)
        {
            double temp=a[i].x;
            a[i].x=a[i].z;
            a[i].z=(-temp);
        }
        double temp=tempz;
        tempz=tempx;
        tempx=temp;
    }
    if(tempz>tempy)
    {
        printf("90 davaran hol x\n");
        for(int i=0;i<10;i++)
        {
            double temp=a[i].z;
            a[i].z=a[i].y;
            a[i].y=(-temp);
        }
        double temp=tempy;
        tempy=tempz;
        tempz=temp;
    }
    return 0;
}
