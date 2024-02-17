#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second >= b.second;
}

int main() {
    int n, m, last = 1;
    cin >> n >> m;
    if (m == 0) {
        cout << 1;
        return 0;
    }
    map<int, int> d;
    vector<int> color;
    map<int, vector<int>> Map;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        d.insert({i, 0});
        c.push_back(-1);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        d[a - 1]++;
        if (Map.find(a - 1) == Map.end()) {
            vector<int> v;
            v.push_back(b - 1);
            Map.insert({a - 1, v});
        } else {
            Map[a - 1].push_back(b - 1);
        }
        d[b - 1]++;
        if (Map.find(b - 1) == Map.end()) {
            vector<int> v;
            v.push_back(a - 1);
            Map.insert({b - 1, v});
        } else {
            Map[b - 1].push_back(a - 1);
        }
    }
    vector<pair<int, int> > A;

    for (auto &it: d) {
        A.emplace_back(it);
    }
    sort(A.begin(), A.end(), cmp);
    color.push_back(1);
    bool first = true;

    for (auto &it: A) {
        if (first || it.second == 0) {
            c[it.first] = 1;
            first = false;
        } else {
            vector<int> co(color);
            for (auto &i: Map[it.first]) {
                if (c[i] != -1 && find(co.begin(), co.end(), c[i]) != co.end())
                    co.erase(remove(co.begin(), co.end(), c[i]), co.end());
                if (co.empty())
                    break;
            }
            if (co.empty()) {
                c[it.first] = ++last;
                color.push_back(last);
            } else
                c[it.first] = co[0];
        }
    }
    cout << last << endl;
}