void dfs(int s) {
        if (visited[s]) return;
        visited[s] = true;
        // process node s
        for (auto u: adj[s]) {
            dfs(u); }
}