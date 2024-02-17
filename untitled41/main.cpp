#include <stdio.h>
#include <iostream>
using namespace std;
//void merge(int []/*array*/,int /*start point*/,int /*middle point*/,int /*end point*/);
//void sort(int []/*array*/,int /*start point*/,int /*end point*/);
int binary_search(int *a/*array*/, int /*first*/first, int /*last*/last, int /*number*/x);
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
/*int binarysearch(int *arr, int length, int num)
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
    int n,r;
    cin>>n>>r;
    int a[10000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x = a[0];
    MS(a,0,n-1);
    int y = binary_search(a, 0,  n - 1, x);
    int i=y,s=1;
    while((i<n-1)&&(a[i]+r>=a[i+1]))
    {
        s++;
        i++;
    }
    i=y;
    while((i>0)&&(a[i]-r<=a[i-1]))
    {
        s++;
        i--;
    }
    printf("%d\n",s);
    return 0;
}
/*void sort(int a[],int first,int last)
{
    if(first>=last)
    {
        return ;
    }
    if(first+1==last)
    {
        if(a[first]>a[last])
        {
            int tmp=a[first];
            a[first]=a[last];
            a[last]=tmp;
        }
        return ;
    }
    //printf("SORTING!\n");
    int mid=(last+first)/2;
    sort(a,first,mid);
    sort(a,mid+1,last);
    merge(a,first,mid,last);
    return ;
}
void merge(int a[],int start,int mid,int last)
{
    //printf("MERGING!\n");
    int a_first[5000],a_last[5000];
    int il=mid-start+1,jl=last-mid,k=start;  //xl : x length
    for(int ii=0;ii<il;ii++)
    {
        a_first[ii]=a[ii+start];
    }
    int i=0;
    for(int ii=0;ii<jl;ii++)
    {
        a_last[ii]=a[ii+mid+1];
    }
    int j=0;
    while((i<il)&&(j<jl))
    {
        if(a_first[i]<=a_last[j])
        {
            a[k]=a_first[i];
            i++;k++;
        }
        else
        {
            a[k]=a_last[j];
            j++;k++;
        }
    }
    while(i<il)
    {
        a[k]=a_first[i];
        i++;k++;
    }
    while(j<jl)
    {
        a[k]=a_last[j];
        j++;k++;
    }
    return ;
}*/
int binary_search(int *a, int first, int last, int x)
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
        return binary_search(a, first, mid - 1, x);
    }
    return binary_search(a, mid + 1, last, x);
}