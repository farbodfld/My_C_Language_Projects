#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int A;  // resturan koobaba
    int B;  // restiran narenjestan
    int C;  // hardo resturan
    int N;  // tedad kol
    cin>>A>>B>>C>>N;
    int failshodegan;
    if(A>=C && B>=C){
       failshodegan = (N - ((A+B)-C));
       cout<<failshodegan<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
    return 0;
}