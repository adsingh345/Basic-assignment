#include <stdio.h>

int main() {
    int n, m, i, j, u, v, is_directed;

    // 1. Input number of vertices and edges
    printf("Enter number of vertices (n) and edges (m): ");
    scanf("%d %d", &n, &m);

    // 2. Initialize an n x n adjacency matrix with 0
    int adj[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // 3. Determine graph type
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &is_directed);

    // 4. Input m pairs of edges and update the matrix
    printf("Enter %d pairs of edges (u v):\n", m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        
        // Mark edge from u to v
        adj[u][v] = 1;
        
        // If undirected, also mark edge from v to u
        if (!is_directed) {
            adj[v][u] = 1;
        }
    }

    // 5. Output the n x n adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
