
#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;
const int M = 2e5 + 137;
int n, q;
int reqType, x, y, z;

int main()
{
    cin >> n >> q;
    int arr[n+1], minn[n+1], maxx[n+1], dataa[n+1];
    for (size_t i = 1; i <= n; i++)
    {
        arr[i] = i;
        minn[i] = i;
        maxx[i] = i;
        dataa[i] = i;
    }
    while(q--)
    {
        cin >> reqType;
            if(reqType==1)
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
                    for(auto a : set1)
                        arr[a] = x;
                }
                break;
            }
            else
            {
                cin >> z;
                while(arr[z]!= z)
                    z = arr[z];
                cout << dataa[z] << " " << minn[z] << " " << maxx[z] << "\n";
                break;
            }
        }
    }
