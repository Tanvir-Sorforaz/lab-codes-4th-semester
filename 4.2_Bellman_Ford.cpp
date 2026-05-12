//Bellman-Ford Algorithm
#include <bits/stdc++.h>
using namespace std;

struct node {
    int u, v, wt;
    node(int _u, int _v, int _wt) {
        u = _u;
        v = _v;
        wt = _wt;
    }
};
int main() {
    int N, m;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> m;
    vector<node> edges;
    cout << "Enter edges (u v weight): " << endl;

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    int src;
    cout << "Enter source node: ";
    cin >> src;
    int inf = 10000000;
    vector<int> dist(N + 1, inf);
    dist[src] = 0;
    // Relax all edges N - 1 times
    for(int i = 1; i <= N - 1; i++) {
        for(auto it : edges) {
            if(dist[it.u] != inf && dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }
    // Check negative cycle by trying to relax once more. If we can still relax, then there is a negative cycle.
    int flag = 0;
    for(auto it : edges) {
        if(dist[it.u] != inf && dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle" << endl;
            flag = 1;
            break;
        }
    }
    // Print distances
    if(!flag) {
        cout << "vertex distance_from_source" << endl;
        for(int i = 1; i <= N; i++) {
            cout << i << "      ";
            if(dist[i] == inf) {
                cout << "INF" << endl;
            }
            else {
                cout << dist[i] << endl;
            }
        }
    }
    return 0;
}

/*
Enter number of nodes and edges: 6 8
Enter edges (u v weight): 
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
5 4 2
4 6 1
5 6 5
Enter source node: 1
vertex distance_from_source
1      0
2      2
3      3
4      8
5      6
6      9
*/




// for negative cycle 
/*
Enter number of nodes and edges: 4 5
Enter edges (u v weight): 
3 2 -10
4 3 3
1 4 5
1 2 4
2 4 5
Enter source node: 1
Negative Cycle
*/

