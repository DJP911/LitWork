#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int n) {
    vector<int> color(n, -1); // -1 represents uncolored, 0 and 1 are colors
    queue<int> q;

    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            color[start] = 0; // Assign color 0 to the starting node
            q.push(start);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u]; // Assign the opposite color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; // Conflict: Adjacent nodes have the same color
                    }
                }
            }
        }
    }

    return true; // No conflicts, the graph is bipartite
}

int main() {
    // Exercise-1
    vector<vector<int>> graph1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    int n1 = 4;
    cout << "Exercise-1 Output: " << (isBipartite(graph1, n1) ? "true" : "false") << endl;

    // Exercise-2
    vector<vector<int>> graph2 = {{1, 2, 3}, {0, 2}, {0, 1}, {0}};
    int n2 = 4;
    cout << "Exercise-2 Output: " << (isBipartite(graph2, n2) ? "true" : "false") << endl;

    // Exercise-3
    vector<vector<int>> graph3 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    int n3 = 4;
    cout << "Exercise-3 Output: " << (isBipartite(graph3, n3) ? "true" : "false") << endl;

    return 0;
}
