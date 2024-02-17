#include<stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //2 araye joda tarif mikonim
    int L[n1], v[n2];

    /* dade haro too araye haye jadid mirizim */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        v[j] = arr[m + 1+ j];

    // 2 araye i va j ro sort kardim va ba oon k ro sort mikonim
    i = 0;
    j = 0;
    k = l; // az 1 shroo mikonim o i va j ro edamash mizarim
    while (i < n1 && j < n2)
    {
        if (L[i] >= v[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = v[j];
            j++;
        }
        k++;
    }
    // agar i be enteha nareside bood ezafe mikonim
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /*agar j be tah nareside bood ezafe mikonim*/
    while (j < n2)
    {
        arr[k] = v[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void MF(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        MF(arr, l, m);
        MF(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


/* tabeyi bara print sort shode */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main()
{
    int a[1000];
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
    {
       scanf("%d",&a[i]);
    }

    MF(a, 0, n - 1);
    for (int j = 0; j < n ; ++j)
    {
        printf("%d ",a[j]);

    }

    return 0;
}
