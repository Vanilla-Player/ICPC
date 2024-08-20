int ids[MAX_N];
vector<vector<int> > adj(MAX_N);
vector<int> top_list;
bool not_pos = false;

void dfs(int node){

    for(auto v: adj[node]){
        if(ids[v] == 2){
            continue;
        }
        if(ids[v] == 1){
            not_pos = true;
        }
        if(ids[v] == 0){
            ids[v] = 1;
            dfs(v);
            if(not_pos) return;
        }
    }
    ids[node] = 2; // Mark the node as fully processed
    top_list.pb(node); // Add node to the topological sort list 
   
}
// Recordar que queda ordenado al reves y no se puede sortear! Pero le podes aplicar un reverse 
fora(i,1, n){
    if(ids[i] == 0){
        ids[i] = 1;
        dfs(i);
    }
    if(not_pos){
        cout<< "NOT POSSIBLE" << endl;
        return 0;
    }
}

for (int i = top_list.size() - 1; i >= 0; i--)
{
    cout << top_list[i] << " ";
}