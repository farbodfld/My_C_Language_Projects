#include <iostream>
using namespace std;

int main() {
    int r , c;
    cin>>r>>c;
    int **a;
    a = new int* [r];
    for (int j = 0; j < r ; ++j)
    {
        a[j] = new int [c];
        for (int i = 0; i < c ; ++i)
        {
            cin>>a[j][i];

        }

    }
    //int **b;
    //a = new int* [r];
    for (int j = 0; j < r ; ++j)
    {
        //a[j] = new int [c];
        int x;
        for (int i = 0; i < c ; ++i)
        {
            cin>>x;
            a[j][i]+=x;
        }

    }
    for (int k = 0; k < r ; ++k)
    {
        for (int i = 0; i < c ; ++i)
        {
            cout<<a[k][i]<<" ";

        }
        cout<<endl;
    }
    return 0;
}