#include <iostream>
#include <math.h>
using namespace std;


long long int masiryab(int n, int m)
{
    // halat paye
    if (m == 0 || m == n)
        return 1;


    return (masiryab(n - 1, m - 1) * (n))/m;
           /*masiryab(n - 1, k); ba in ravesh ba time bala tar mohasebe mishe
           ke monaseb nist*/
}


int main()
{
    int n , m ;
    cin >> n >> m;
    cout <<masiryab(m + n, n);
    return 0;
}
