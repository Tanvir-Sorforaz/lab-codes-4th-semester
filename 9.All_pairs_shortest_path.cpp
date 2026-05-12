//all pairs shortest path( Floyd Warshall Algorithm)
#include <bits/stdc++.h>
using namespace std;

int main() {

    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int INF = 10000000;

    vector<vector<int>> dist(V + 1, vector<int>(V + 1, INF));

    // Distance from node to itself = 0
    for(int i = 1; i <= V; i++) {
        dist[i][i] = 0;
    }

    cout << "Enter edges (u v weight): " << endl;

    for(int i = 0; i < E; i++) {

        int u, v, wt;

        cin >> u >> v >> wt;

        dist[u][v] = wt;
    }

    // Floyd Warshall
    for(int via = 1; via <= V; via++) {

        for(int i = 1; i <= V; i++) {

            for(int j = 1; j <= V; j++) {

                if(dist[i][via] != INF && dist[via][j] != INF) {

                    dist[i][j] = min(dist[i][j],
                                     dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    // Print shortest distance matrix
    cout << endl;
    cout << "Shortest Distance Matrix:" << endl;

    for(int i = 1; i <= V; i++) {

        for(int j = 1; j <= V; j++) {

            if(dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}


/*
Enter number of vertices and edges: 4 5
Enter edges (u v weight): 
1 2 3
1 4 7
2 3 2
3 4 1
4 2 6

Shortest Distance Matrix:
0 3 5 6 
INF 0 2 3 
INF 7 0 1 
INF 6 8 0
*/