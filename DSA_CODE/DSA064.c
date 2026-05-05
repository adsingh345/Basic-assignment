#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void performBFS(int n, vector<int> adj[], int s) {
        vector<bool> visited(n, false);
        queue<int> q;

        // 1. Mark the source as visited and enqueue it
        visited[s] = true;
        q.push(s);

        cout << "BFS Traversal order: ";

        while (!q.empty()) {
            // 2. Dequeue a vertex and print it
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            // 3. Get all adjacent vertices of the dequeued vertex
            for (int neighbor : adj[curr]) {
                // 4. If a neighbor has not been visited, mark it and enqueue it
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};
