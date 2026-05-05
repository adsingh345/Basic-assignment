#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int adj[MAX][100]; // Adjacency list (simplified for small neighbor counts)
int degree[MAX];   // Degree of each node
int visited[MAX];

void dfs(int node) {
    visited[node] = 1;
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

    // Build the adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;
    }

    int components = 0;
    // Nodes are typically 1-indexed based on the sample
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }

    printf("%d\n", components);

    return 0;
}
