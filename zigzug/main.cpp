#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int fn = 0;
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        fn = pow(-1,i)*i;
        result += fn;
    }
    cout<<result<<endl;
    return 0;
}