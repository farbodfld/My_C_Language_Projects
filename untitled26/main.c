#include <stdio.h>
#include <stdbool.h>
bool chekprime(int num , int counter , int i)
{
    if(i<num)
        return (num%i== 0) ? chekprime(num,counter + 1,i + 1):chekprime(num,counter,i + 1);
    return(counter == 1) ? true:false;

  /*scanf("%d",&num);
  counter = 0;
    for ( i = 1; i <= num ; ++i)
    {
        if(num % i == 0)
        {
            counter++;
        }
    }
    if(counter == 2)
        printf("Yes");
    else
        printf("No");*/
}


int main()
{
    int num,counter = 0,i = 1;
    scanf("%d",&num);
    if(chekprime(num,counter,i))
        printf("Yes");
    else
        printf("No");
    return 0;
}