#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;
double miangin(int data[], int n)
{
    double sum = 0;
    for (int j = 0; j < n ; ++j)
    {
        sum += data[j];

    }
    sum = sum / n;
    return sum;
}
double miane(int data[], int n)
{
    double miane;

    if(n % 2 != 0)
             miane = data[n/2];
    else
      miane = (data[(n - 1) / 2] + data[((n - 1)/2) + 1]) / 2.0;
    return miane;
}
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

double varience(int data[], int n, double miangin)
{
    double varience,sum=0;
    for(int i=0;i<n;i++)
        sum += (data[i]*data[i]);
    varience=(sum/n)-(miangin * miangin);
    return varience;
}
double zaribtaghirat(double var, double avg)//zarib taghirat
{
    double zaribtaghirat=(sqrt(var) / avg);
    return zaribtaghirat;
}

double natije(double a)
{
    int x=a*1000;
    return x;
}



int main() {
    int n;
    scanf("%d",&n);
    int data[n];
    for (int i = 0; i < n ; ++i)
    {
        cin>>data[i];
    }
    MS(data, 0, n - 1);
    cout<<setprecision(3)<<fixed<<miane(data,n)<<endl;
    double avg = miangin(data,n);
    double Varience = varience(data,n,avg);
    double Cov = zaribtaghirat(Varience,avg);
    cout<<(natije(Cov)/1000)<<endl;
    return 0;
}