#include <stdio.h>
void hanoi(int m , char from , char help , char to)
{
    if(m == 1)
        printf("%c->%c\n",from,to);
    else
    {
        hanoi(m - 1, from, to, help);
        printf("%c->%c\n",from,to);
        hanoi(m - 1, help, from, to);
    }
}
void hanoikhas(int m , char from , char help , char to)
{
    if(m == 2){
        printf("%c->%c\n",from,to);
        printf("%c->%c\n",help,to);}
    else
    {
        hanoikhas(m - 2 , from , help , to);
        hanoi(m - 2 , to , from , help);
        printf("%c->%c\n",from,to);
        hanoi(m - 1 , help , from , to);
    }
}

int main() {
    int m;
    scanf("%d",&m);
    hanoikhas(m , 'A','B','C');
    return 0;
}