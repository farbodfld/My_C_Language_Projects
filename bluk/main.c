#include <stdio.h>
int bluk(int m,int n)
{
    int natije = 0;
    if (m > n)  natije = natije + bluk(m - 1, n);
    for (int j = n; j <= m; ++j) natije = natije + bluk(m - j - 1, n);
    return m<n ? 1 : (m==n ? 2:natije);
}
int main() {

        int m, n;
        scanf("%d %d",&m,&n);
        if (n==0)   n++;
        printf("%d",bluk(m , n));

    return 0;
}


