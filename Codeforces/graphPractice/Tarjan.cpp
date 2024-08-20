#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;

vector<int> adj[MAX_N];
vector<vector<int> >comps(MAX_N); // Guarda componentes
int ids[MAX_N]; // ID del nod
int low[MAX_N]; // lminimo nodo visitado
stack<int> in_process;// Tiene  las componentes que estan en ejecucion
vector<int> stackMember(MAX_N); // Para ver si el nodo esta en el stack
// Estar en el stack es diferente a estar visitado id[node] != -1
int id = 0;

void tarjan(int node){
    id++;
    low[node] = ids[node] = id;
    in_process.push(id);
    stackMember[id] = 1;
    for(auto v: adj[node]){
        if(ids[v] == -1){
            tarjan(v);
            low[node] = min(low[node], low[v]);
        }
        if(stackMember[v]){
            low[node] = min(low[node], ids[v]);
        }
    }
    if(low[node] == ids[node]){
        while(node != in_process.top()){
            int n = in_process.top();
            stackMember[n] = 0;
            comps[node].push_back(n); // agrego a la componente
            in_process.pop();
        }
        comps[node].push_back(in_process.top()); // Este en el tope es el node, es lo mismo hacer comps[node].push_back(node);
        stackMember[node] = 0;
        in_process.pop(); // popeo node del stack
    }
}
int main(){
    int n,c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        ids[i] = -1;
        low[i] = -1;
    }
    for(int i = 0; i < c ; i++){
        int s,e;
        cin >> s >> e;
        adj[s].push_back(e);
    }

    for(int i = 1; i <= n ; i++){
        if(ids[i] == -1){
            tarjan(i);
        }
    }

    for(int i = 1; i <= n ; i++){
        if(comps[i].size() != 0){
            for (int j = 0; j < comps[i].size(); j++)
            {
                cout << comps[i][j] << " ";
            }
            cout << endl;
        }
    }

}
