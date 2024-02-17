#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, m; cin >> n >> m;
    vector<vector<long long>> a(m, vector<long long>(3));
    for (int i = 0; i < m; i++) {
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    }
    sort(a.begin(), a.begin() + m);
    /*for (int i = 0; i < m; i++)
        cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << "\n";*/

    long long point = 0;
    int pos = 0;
    vector<vector<long long>> stor_end(m, vector<long long>(2));
    for (int j = 0; j < m; j++) {
        for (int i = pos - 1; i >= 0 && a[j][2] > 0; i--) {
            if (a[j][1] <= stor_end[i][0]) {
                a[j][2]-= stor_end[i][1];
            }
            else break;
        }
        if (a[j][2] > 0) {point+= a[j][2]; stor_end[pos][0] = a[j][0]; stor_end[pos++][1] = a[j][2];}
    }
    cout << point;
    return 0;
}
