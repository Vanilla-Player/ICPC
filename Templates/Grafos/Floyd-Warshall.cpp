// Escrtito como matriz de adjacencia, encuentra todso los caminos mas cortos en una corrida O(n^3)
// Inicializacion
for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
           if (i == j) distance[i][j] = 0;
           else if (adj[i][j]) distance[i][j] = adj[i][j];
           else distance[i][j] = INF;
} }

// Algoritmo
for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= n; j++) {
               distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
} }
}