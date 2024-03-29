#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    Edge* edge;
};

Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];

    return graph;
}

class subset {
public:
    int parent;
    int rank;
};


int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent
                = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight < b1->weight;
}

void KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
          myComp);

    subset* subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {

        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    if (e != V - 1) {
        cout << "-1\n";
    }
    else {
        long long minimumCost = 0LL;
        for (i = 0; i < e; ++i)
        {
            minimumCost = minimumCost + (long long)result[i].weight;
        }
        cout << minimumCost << endl;
    }
}


int main()
{
    int V, E, C; cin >> V >> E >> C;
    int u, v, w;
    Graph* graph = createGraph(V, E);

    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> w;
        --u; --v;
        graph->edge[i].src = u;
        graph->edge[i].dest = v;
        graph->edge[i].weight = w;
    }
    if (V == 0) {
        cout << "0\n";
        return 0;
    }
    KruskalMST(graph);

    return 0;
}


/*
4 5 3
1 2 100
1 3 10
2 3 100
2 4 19
3 4 100


4 2 100
1 2 100
3 4 100

*/