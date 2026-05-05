#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    // Recursive DFS function
    void dfs(int current, vector<int> adj[], vector<bool>& visited) {
        // 1. Mark the current node as visited
        visited[current] = true;
        
        // 2. Print (or store) the vertex in the traversal order
        cout << current << " ";

        // 3. Recur for all the vertices adjacent to this vertex
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    void performDFS(int n, vector<int> adj[], int s) {
        vector<bool> visited(n, false);
        cout << "DFS Traversal starting from " << s << ": ";
        dfs(s, adj, visited);
        cout << endl;
    }
};

int main() {
    int n = 4; // Number of vertices
    vector<int> adj[n];

    // Example edges: 0-1, 0-2, 1-2, 2-0, 2-3, 3-3
    adj[0] = {1, 2};
    adj[1] = {2};
    adj[2] = {0, 3};
    adj[3] = {3};

    Graph g;
    g.performDFS(n, adj, 2); // Start DFS from vertex 2

    return 0;
}
