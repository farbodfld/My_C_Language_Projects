#include <stdio.h>

int main( )
{
    int n;
    scanf("%d",&n);
    int shomarandeNomadadeAVAL= 0;
    for (int i = 2; i < n+1 ; i++)
    {
        int count = 0;
        for (int j = 2; j < i; ++j) {
            if (i%j == 0)
                count++;
        }
        if (count == 0 && n%i == 0)
        {
            shomarandeNomadadeAVAL++;
            int tedadeTavan=0;
            while (n%i == 0)
            {
                n /= i;
                tedadeTavan++;
            }
            if (shomarandeNomadadeAVAL == 1)
            {
                if (tedadeTavan == 1)
                    printf("%d",i);
                else
                    printf("%d^%d",i,tedadeTavan);
            } else{
                if (tedadeTavan == 1)
                    printf("*%d",i);
                else
                    printf("*%d^%d",i,tedadeTavan);

            }
        }
    }
    return 0;
}