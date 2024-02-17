#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
struct vec
{
    double a[10];
};
double zd(struct vec /*first*/,struct vec /*second*/);
double zd(struct vec v1,struct vec v2)
{
    double p=0;
    for(int i=0;i<10;i++)
    {
        p+=((v1.a[i]) * (v2.a[i]));
    }
    return p;
}
int main()
{
    struct vec v[10],u[10];
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            v[i].a[j]=((rand()%101)-50);
        }
    }
    for(int i=0;i<10;i++)
    {
        u[i]=v[i];
        for(int j=0;j<i;j++)
        {
            double temp = zd(v[i],u[j]);
            temp /= zd(u[j],u[j]);
            for(int k=0;k<10;k++)
            {
                u[i].a[k] -= (temp*u[j].a[k]);
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        double size=0;
        for(int j=0;j<10;j++)
        {
            size+=(u[i].a[j] * u[i].a[j]);
        }
        size=sqrt(size);
        for(int j=0;j<10;j++)
        {
            u[i].a[j]/=size;
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=i;j<10;j++)
        {
            printf("zarb dakheli %d va %d : %lf \n",i+1,j+1,zd(u[i],u[j]));
        }
    }
    return 0;
}
