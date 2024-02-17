#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<long long, int>, null_type, less<pair<long long, int>>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

const int N = 2e5 + 9;
map<int, int> mx[N];
map<int, int> mem[N];
vector<int> vi[N];

int solve(int node, int par) {
    if (mx[node][par])
        return mx[node][par];
    int rt = 0;
    for (int ch : vi[node])
        if (ch != par) {
            rt = max(rt, 1 + solve(ch, node));
        }
    return mx[node][par] = rt;
}

int build(int node, int par) {
    if (mem[node][par])
        return mem[node][par];
    int max = solve(node, par);
    int cur = node;
    for (int ch : vi[node])
        if (ch != par) {
            if (max == 1 + solve(ch, node)) {
                cur = build(ch, node);
                break;
            }
        }
    return mem[node][par] = cur;
}

pair<int, vector<int>> getMax(int node, int cnt) {
    if (vi[node].size() < cnt)
        return {0, {}};
    vector<pair<int, int>> v;
    for (int ch : vi[node])
        v.push_back({solve(ch, node) + 1, build(ch, node)});
    sort(v.rbegin(), v.rend());
    int sum = 0;
    vector<int> rt;
    for (int i = 0; i < cnt; i++) {
        sum += v[i].first;
        rt.push_back(v[i].second);
    }
    if (cnt == 2)
        rt.push_back(node);
    return {sum, rt};
}

int main() {
    int arr1[3];
    int i1 = 0;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vi[a].push_back(b);
        vi[b].push_back(a);
    }
    pair<int, vector<int>> ans = {0, {}};
    for (int i = 1; i <= n; i++) {
        ans = max(ans, getMax(i, 2));
        ans = max(ans, getMax(i, 3));
    }
    cout << ans.first << endl;
    for (auto it : ans.second) {
        arr1[i1] = it;
        i1++;
    }
    sort(arr1, arr1 + 3);
    for (int i = 0; i < 3; i++) {
        cout << arr1[i];
        cout << "\n";
    }
    return 0;
}