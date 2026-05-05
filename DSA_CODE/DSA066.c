#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int u, vector<int> adj[], vector<bool>& visited, vector<bool>& pathVisited) {
        visited[u] = true;
        pathVisited[u] = true; // Mark node as part of current path

        for (int v : adj[u]) {
            // If node not visited, recurse
            if (!visited[v]) {
                if (dfs(v, adj, visited, pathVisited)) return true;
            } 
            // If node is already in the current path, cycle detected!
            else if (pathVisited[v]) {
                return true;
            }
        }

        // Backtrack: remove node from current path stack
        pathVisited[u] = false;
        return false;
    }

    void isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVisited)) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
    }
};
