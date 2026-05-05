#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int u, vector<int> adj[], vector<bool>& visited) {
        // 1. Mark current node as visited
        visited[u] = true;
        
        // 2. Output the traversal order
        cout << u << " ";

        // 3. Recur for all neighbors
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited);
            }
        }
    }

    void startDFS(int n, vector<int> adj[], int s) {
        vector<bool> visited(n, false);
        dfs(s, adj, visited);
    }
};
