#include <stdio.h>
#include <math.h>

void moshkel() {
    int static adad;
    scanf("%d", &adad);
    int g = 0;
    while (adad > 0) {
        int c = adad;
        c /= 2;
        g++;
    }
    printf("pow(2 , g)");
}

int main() {
    int a;
    scanf("%d",&a);
    moshkel();
    return 0;
}