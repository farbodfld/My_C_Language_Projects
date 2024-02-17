#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int H){
    int i, j, k, T;
    j = l;
    for(i = m + 1 ; i <= H ; i++){
        while(arr[j] <= arr[i] && j < i)
            j++;
        if(j == i)
            break;
        T = arr[i];
        for(k = i ; k > j ; k --)
            arr[k] = arr[k - 1];
        arr[j] = T;
    }
}

void MS(int *arr, int L, int H){
    if(L >= H)
        return;
    int mid = (L + H) / 2;
    MS(arr, L, mid);
    MS(arr, mid + 1, H);
    merge(arr, L, mid, H);
}
int binarysearch(int *a, int first, int last, int x)//komak gerefte shode
{
    if(last<first)
    {
        return -1;
    }
    int mid=(first+last)/2;
    if(a[mid]==x)
    {
        return mid;
    }
    if(a[mid]>x)
    {
        return binarysearch(a, first, mid - 1, x);
    }
    return binarysearch(a, mid + 1, last, x);
}
/*int binarysearch(int *arr, int length, int num) //moshkeli vjood dasht ke hal nashod
{
    int min, low = 0, high = length-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(num < arr[mid])
            high = mid-1;
        else if(num > arr[mid])
            low = mid +1;
        else return mid;
    }
    return -1;
}*/


int main()
{
    int n,r,sum = 0;
    cin>>n>>r;
    int a[10000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x = a[0];
    MS(a , 0 , n - 1);
   int v = binarysearch(a , 0 , n - 1 , x);
   int i = v , s = 1;
   /*for ( i ; i < (n - 1) && (a[i] + r >= a[i+1]) ; ++i) //ba for 116 mide
     {
         //if ((n + a[i]) < r)
         s ++;
     }
   int j = v;
    for ( j ; (j > 0 && a[i] - r <= a[i-1] ); --j)
    {
        s ++;
    }*/
    /*do                            // ba do while 136 mide
    {
        s++;
        i--;
    }
    while((i>0)&&(a[i]-r<=a[i-1]));
    i=v;
    do
   {
       s++;
       i++;
   }
    while((i<n-1)&&(a[i]+r>=a[i+1]));*/
    while((i<n-1)&&(a[i]+r>=a[i+1]))    // faghat ba while 200 mide
                                        // eshkale kar ro hich kas nafahmid
    {
        s++;
        i++;
    }
    i=v;
    while((i>0)&&(a[i]-r<=a[i-1]))
    {
        s++;
        i--;
    }
    cout<<s<<"\n"<<endl;
    return 0;
}