#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int adj[MAX][100]; // Simplistic adjacency list
int degree[MAX];
int visited[MAX];
int count = 0;

void dfs(int node) {
    visited[node] = 1;
    count++; // Count each unique node visited
    for (int i = 0; i < degree[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Add edge for undirected graph
        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;
    }

    // Start DFS from node 1 (assuming 1-based indexing)
    if (n > 0) dfs(1);

    // If the count of visited nodes equals total nodes, it's connected
    if (count == n) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}
