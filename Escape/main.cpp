#include <iostream>

using namespace std;

void check(bool **res,bool **f,int m,int n,int i,int j){
    res[i][j] = 1;
    if(i>0 && res[i-1][j]==0 && f[i-1][j]==1) check(res,f,m,n,i-1,j);
    if(j>0 && res[i][j-1]==0 && f[i][j-1]==1) check(res,f,m,n,i,j-1);
    if(i<n-1 && res[i+1][j]==0 && f[i+1][j]==1) check(res,f,m,n,i+1,j);
    if(j<m-1 && res[i][j+1]==0 && f[i][j+1]==1) check(res,f,m,n,i,j+1);
}

int main()
{
    int n,m;
    cin >> n >> m;
    bool *f[n];
    for(int i =0;i<n;i++){
        f[i]=new bool[m];
    }
    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c;
            if(c == '#'){
                f[i][j] = 0;
            }
            else{
                f[i][j] = 1;
            }
        }
    }
    bool *res[n];
    for(int i =0;i<n;i++){
        res[i]=new bool[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        if(f[i][m-1])
            check(res,f,m,n,i,m-1);
    }
    int p = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(res[i][j]) p++;
        }
    }
    cout<<p;
    return 0;
}