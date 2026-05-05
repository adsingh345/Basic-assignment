#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void dfs(int u, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
        visited[u] = true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, st);
            }
        }

        // Push to stack after visiting all neighbors
        st.push(u);
    }

    void topologicalSort(int V, vector<int> adj[]) {
        stack<int> st;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        // Print the contents of the stack
        cout << "Topological Sort: ";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};
