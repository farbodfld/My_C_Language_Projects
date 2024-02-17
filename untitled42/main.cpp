#include <iostream>

using namespace std;
/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}*/

#include <stdio.h>

int main() {
    for (int i = 1; i <= 10 ; ++i)
    {
        for (int j = 1; j <= 10 ; ++j)
            //cout<<i * j;
            printf("%2d",i * j);
        printf("\n");



    }
    return 0;
}