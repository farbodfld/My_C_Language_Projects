#include <bits/stdc++.h>
#include<vector>
using namespace std;
const int max_n=100005;
vector<int> graph[max_n];
int main() {
    long long int n, dp[max_n], val[max_n], max, from[max_n], max_index, mx = 0;
    vector<int> tr;
    vector<int> ti;
    bool minus[max_n];
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>val[i];
        if (val[i] < 0) {
            val[i] = 0;
            minus[i] = true;
        }
        else minus[i] = false;
    }
    dp[1] = val[1];
    dp[2] = val[2];
    from[1] = 0;
    from[2] = 0;
    max = dp[1];
    max_index = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = val[i] + max;
        from[i] = max_index;
        if (dp[i - 1] > max) {
            max = dp[i - 1];
            max_index = i - 1;
        }
    }
    if (dp[n] > max)max_index = n;
    while (max_index != 0) {
        if (!minus[max_index]) {
            ti.push_back(max_index);
        }
        max_index = from[max_index];
    }
    for (int i=0;i<ti.size();i++)
        mx += val[ti[i]];
    cout << mx << endl;
    cout << ti.size() << "\n";
    sort(ti.begin(), ti.end());
    for (int i = 0; i < ti.size(); i++)
    {
        cout << ti[i] << " ";
    }
}