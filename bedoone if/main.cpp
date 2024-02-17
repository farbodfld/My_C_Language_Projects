#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    int valuemin = a < b ? a:b;
    int valuemin2 = valuemin < c ? valuemin:c;
    int valuemax = a > b ? a:b;
    int valuemax2 = valuemax > c ? valuemax:c;
    cout<<valuemin2<<endl<<valuemax2<<endl;
    return 0;
}