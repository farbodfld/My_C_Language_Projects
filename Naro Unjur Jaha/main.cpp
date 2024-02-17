#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unsigned long long n, m, k;
    cin >> n >> m >> k;
    map<unsigned long long, vector<pair<unsigned long long, unsigned long long> *>> graph;
    for (unsigned long long i = 0; i < n; ++i) {
        graph.emplace(i + 1, vector<pair<unsigned long long, unsigned long long> *>());
    }
    for (unsigned long long i = 0; i < m; ++i) {
        unsigned long long c1, c2;
        unsigned long long w;
        cin >> c1 >> c2 >> w;
        graph[c1].push_back(new pair<unsigned long long, unsigned long long>(c2, w));
        graph[c2].push_back(new pair<unsigned long long, unsigned long long>(c1, w));
    }
    map<unsigned long long, unsigned long long> distance;
    priority_queue<pair<unsigned long long, unsigned long long>> queue;
    set<unsigned long long> seen;
    queue.push(pair<unsigned long long, unsigned long long>(0, 1));
    distance.insert(pair<unsigned long long, unsigned long long>(1, 0));
    unsigned long long d = 0;
    bool found = false;
    while (!queue.empty()) {
        unsigned long long c = queue.top().second;
        d = -queue.top().first;
        queue.pop();
        if (seen.find(c) != seen.end())
            continue;
        seen.insert(c);
        if (seen.size() == k) {
            found = true;
            break;
        }
        for (pair<unsigned long long, unsigned long long> *e: graph[c]) {
            if (seen.find(e->first) != seen.end())
                continue;
            if (distance.count(e->first) == 0)
                distance.insert(pair<unsigned long long, unsigned long long>(e->first, distance[c] + e->second + 1));
            if (distance[e->first] > distance[c] + e->second) {
                distance[e->first] = distance[c] + e->second;
                queue.push(pair<unsigned long long, unsigned long long>(-(distance[c] + e->second), e->first));
            }
        }
    }
    if (!found) {
        cout << -1 << endl;
        return 0;
    }
    cout << d << endl;
    return 0;
}