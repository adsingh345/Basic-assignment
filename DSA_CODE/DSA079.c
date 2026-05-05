#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Pair format: {distance, node}
typedef pair<int, int> pii;

void dijkstra(int n, vector<vector<pii>>& adj, int source) {
    // Initialize distances with infinity
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we already found a shorter path to u, skip it
        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Output distances (assuming 1-based indexing for sample)
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Assuming undirected based on previous context
    }

    int source;
    cin >> source;

    dijkstra(n, adj, source);

    return 0;
}
