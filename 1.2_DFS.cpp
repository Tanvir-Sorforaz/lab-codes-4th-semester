#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of vertices:";
    cin >> n;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1));

    cout << "Enter graph data in matrix form:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter the starting vertex:";
    cin >> start;

    vector<bool> visited(n + 1, false);
    stack<int> st;

    st.push(start);
    

    cout << "The node which are reachable are:\n";

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            //in reverse order to correct DFS sequence
            for (int i = n; i >= 1; i--) {
                if (graph[node][i] == 1 && !visited[i]) {
                    st.push(i);
                }
            }
        }
    }

    return 0;
}

//example input
/*
Enter the number of vertices:6
Enter graph data in matrix form:
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 0 1
0 1 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0
Enter the starting vertex:1 
The node which are reachable are:
1 2 4 5 3 6
*/
