#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int u, int parent, vector<int> adj[], vector<bool>& visited) {
        visited[u] = true;

        for (int v : adj[u]) {
            // Case 1: Neighbor is not visited, recurse
            if (!visited[v]) {
                if (dfs(v, u, adj, visited)) return true;
            }
            // Case 2: Neighbor is visited and is NOT the parent -> Cycle!
            else if (v != parent) {
                return true;
            }
        }
        return false;
    }

    string hasCycle(int n, vector<int> adj[]) {
        vector<bool> visited(n, false);

        // Check each component (for disconnected graphs)
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) return "YES";
            }
        }
        return "NO";
    }
};
