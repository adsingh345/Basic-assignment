#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find shortest paths from source
vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int S) {
    // Min-priority queue: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Distance array initialized to infinity
    vector<int> dist(V, INT_MAX);

    // Source initialization
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we found a shorter path to u already, skip this stale entry
        if (d > dist[u]) continue;

        // Check neighbors
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 4; // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // Adding edges: {neighbor, weight}
    adj[0].push_back({1, 5});
    adj[0].push_back({2, 8});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 4});
    adj[2].push_back({3, 2});

    int source = 0;
    vector<int> result = dijkstra(V, adj, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << (result[i] == INT_MAX ? -1 : result[i]) << endl;
    }

    return 0;
}
