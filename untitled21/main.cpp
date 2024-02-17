#include <iostream>
#include <cmath>
using namespace std;
void sort(double &a1, double &b1, double &c1)
{
   if (c1 > a1) // mitoonestim az amalvand se amali estefade konim!!
       swap(c1,a1);
   if(b1 > a1)
       swap(b1,a1);
   if(c1 > b1)
       swap(c1,b1);
}
void rond(double &a)
{
    double a1;
    if(fmod(a,1) > 0.30000){
        a = floor(a);
        a = a + 1;
    }
    else {
        a = floor(a);
    }
}
void swap(double &a1, double &b1)
{
   double temp;
   temp = a1;
   a1 = b1;
   b1 = temp;
}

int main() {
    double a1,b1,c1;
    cin>>a1>>b1>>c1;
    sort(a1,b1,c1);
    rond(a1);
    rond(b1);
    rond(c1);
    cout<<a1<<endl;
    cout<<b1<<endl;
    cout<<c1<<endl;
    return 0;
}