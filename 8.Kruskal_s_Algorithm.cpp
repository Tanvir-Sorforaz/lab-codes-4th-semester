#include <bits/stdc++.h>
using namespace std;

int parent[100], RankArr[100];

// Find parent with path compression
int findParent(int node)
{
    if (node == parent[node])
        return node;

    return parent[node] = findParent(parent[node]);
}

// Union by rank
void unionSet(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    if (u != v)
    {
        if (RankArr[u] < RankArr[v])
            parent[u] = v;
        else if (RankArr[u] > RankArr[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            RankArr[u]++;
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    // each edge = {weight, u, v}

    vector<vector<int>> edges;

    cout << "Enter edges in the format (u v w)(example: 0 2 3):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    // sort by weight
    sort(edges.begin(), edges.end());

    // initialize DSU (disjoint set union)
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        RankArr[i] = 0;
    }

    int totalCost = 0;

    for (auto edge : edges)
    {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (findParent(u) != findParent(v))
        {
            totalCost += w;
            unionSet(u, v);
        }
    }

    cout << "Total cost of MST = " << totalCost << endl;   //Minimum Spanning Tree

    return 0;
}

// INPUT and OUTPUT

// Enter the number of vertices and edges: 6 8
// Enter edges in the format (u v w)(example: 0 2 3):
// 0 1 7
// 0 3 3
// 1 3 8
// 1 4 4
// 3 4 2
// 4 5 3
// 1 2 5
// 2 5 2
// Total cost of MST = 14


// for parallel edges and loops 

// Enter the number of vertices and edges: 6 11
// Enter edges in the format (u v w)(example: 0 2 3):
// 0 1 7
// 0 3 3
// 1 3 8
// 1 4 4
// 3 4 2
// 4 5 3
// 1 2 5
// 2 5 2
// 1 2 6
// 2 5 3
// 4 4 2
// Total cost of MST = 14