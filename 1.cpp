
#include<bits/stdc++.h>
#include<queue>
#include<vector>
#include<set>
using namespace std;
const int M = 2e5 + 137;
int n, q;
int reqType, x, y, z;
int arr[M], minn[M], maxx[M], dataa[M];

int main()
{
    cin >> n >> q;
    for (size_t i = 1; i <= n; i++)
    {
        arr[i] = i;
        minn[i] = i;
        maxx[i] = i;
        dataa[i] = i;
    }
    for (size_t i = 0; i < q; i++)
    {
        cin >> reqType;
        switch(reqType)
        {
            case 1:
            {
                cin >> x >> y;
                set<int> set1;
                while(arr[x] != x)
                {
                    set1.insert(x);
                    x = arr[x];
                }
                while(arr[y] != y)
                {
                    set1.insert(y);
                    y = arr[y];
                }
                set1.insert(y);
                
                if(x!=y)
                {
                    arr[y] = x;
                    if(minn[x]>minn[y])
                        minn[x] = minn[y];
                    if(maxx[x]<maxx[y])
                        maxx[x] = maxx[y];
                    dataa[x] += dataa[y];
                    for(auto i : set1)
                        arr[i] = x;
                }
                break;
            }
            case 2:
            {
                cin >> z;
                while(arr[z]!= z)
                    x = arr[z];
                cout << dataa[z] << " " << minn[z] << " " << maxx[z] << "\n";
                break;
            }
        }
    }
    
}