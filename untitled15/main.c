#include <stdio.h>
#include <stdbool.h>
double oq_distance_2(int x1, int y1, int x2, int y2)
{
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
bool is_right_tri(int x1, int y1, int x2, int y2, int x3, int y3)
{
  if( oq_distance_2(x1 , y1 , x2 , y2) + oq_distance_2(x3 , y3 , x2 , y2)==oq_distance_2(x1 , y1 , x3 , y3) )
      return 1;
  if( oq_distance_2(x1 , y1 , x3 , y3) + oq_distance_2(x3 , y3 , x2 , y2)==oq_distance_2(x1 , y1 , x2 , y2) )
        return 1;
  if( oq_distance_2(x1 , y1 , x2 , y2) + oq_distance_2(x3 , y3 , x1 , y1)==oq_distance_2(x2 , y2 , x3 , y3) )
        return 1;
  return 0;
}
bool is_Isosceles_tri(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if(oq_distance_2(x1 , y1 , x2 , y2) == oq_distance_2(x1 , y1 , x3 , y3))
        return 1;
    if(oq_distance_2(x1 , y1 , x2 , y2) == oq_distance_2(x2 , y2 , x3 , y3))
        return 1;
    if(oq_distance_2(x3 , y3 , x2 , y2) == oq_distance_2(x1 , y1 , x3 , y3))
        return 1;
    return 0;
}
int main()
{
int x1,y1,x2,y2,x3,y3;
scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
printf("%d %d",is_right_tri( x1,  y1,  x2,  y2,  x3,  y3),is_Isosceles_tri( x1,  y1,  x2,  y2,  x3,  y3));
    return 0;
}