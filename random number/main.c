#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int r;
    srand(time(NULL));


    r = rand() % 11;


    printf("random number is %d",r);
    return 0;
}