// C++ implementation of disjoint set
#include <iostream>
#include <queue>

using namespace std;

class DisjSet {
    int *rank, *parent , *size, n;

public:
    // Constructor to create and
    // initialize sets of n items
    DisjSet(int n) {
        rank = new int[n];
        parent = new int[n];
        size = new int[n];
        this->n = n;
        makeSet();
    }

    int find_size(int c){
        int p = find(c);
        return size[p];
    }

    // Creates n single item sets
    void makeSet() {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Finds set of given item x
    int find(int x) {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {

            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = find(parent[x]);

            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }

        return parent[x];
    }

    // Do union of two sets represented
    // by x and y.
    void Union(int x, int y) {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);

        // If they are already in same set
        if (xset == yset)
            return;

        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }

            // If ranks are same, then increment
            // rank.
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
        int tmp = size[xset] + size[yset];
        size[xset] = tmp;
        size[yset] = tmp;
    }
};

int main() {
    DisjSet ds(500);
    queue<int> q;

    int n;
    cin >> n;
    int arr[n];
    int arr2[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int j = 0; j < n; ++j) {
        cin >> arr2[j];
    }

    for (int k = 0; k < n; ++k) {
        if (ds.find(arr[k]) == ds.find(arr2[k]))
            continue;
        else {
            /*int arr_size = sizeof(arr) / sizeof(arr[k]);
            int arr2_size = sizeof(arr2) / sizeof(arr2[k]);
            int result = arr_size * arr2_size * 2;*/
            q.push(ds.find_size(arr[k]) * ds.find_size(arr2[k]) * 2);
            ds.Union(arr[k] , arr2[k]);
        }
    }

    cout << q.size() << endl;
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}