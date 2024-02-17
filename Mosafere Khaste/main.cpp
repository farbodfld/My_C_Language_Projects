#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000 * 100;

vector<int> graph[max_n];

int bfs(int start) {
    int level[max_n];
    bool visited[max_n];
    for (bool &i : visited) {
        i = false;
    }

    int counter = 0;
    level[start] = 0;

    queue<int> Q;
    Q.push(start);

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        visited[cur] = true;
        for (auto v: graph[cur]) {
            if (!visited[v]) {
                level[v] = level[cur] + 1;
                counter += level[v];
                visited[v] = true;
                Q.push(v);
            }
        }
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u;
        int v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    int node_number = 0, min = INT_MAX;

    for (int j = 0; j < n; ++j) {
        int result = bfs(j);
        if (result < min) {
            min = result;
            node_number = j + 1;
        }
    }
    cout << node_number << endl;
    return 0;
}