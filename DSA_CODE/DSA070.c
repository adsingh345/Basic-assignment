#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, vector<Edge>& edges, int src) {
    // 1. Initialize distances
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[src] = 0;

    // 2. Relax all edges n-1 times
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[edges[j].u] != LLONG_MAX && 
                dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }

    // 3. Check for negative weight cycles (n-th iteration)
    bool hasNegativeCycle = false;
    for (int j = 0; j < m; ++j) {
        if (dist[edges[j].u] != LLONG_MAX && 
            dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    // 4. Output results
    if (hasNegativeCycle) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == LLONG_MAX) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << endl;
    }
}
