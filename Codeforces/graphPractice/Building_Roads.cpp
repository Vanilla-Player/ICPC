#include <bits/stdc++.h>
#define MAXN 202020

using namespace std;


vector<bool> visited(MAXN,false);
int N,M;
vector<vector<int> > adj(MAXN);
vector<int> bridges;


void dfs(int node){


    for (auto child: adj[node])
    {
        if(!visited[child]){
            visited[child] = true;
            dfs(child);
        }
    }
    

}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int row = 0; row < M; row++)
    {
        int node1,node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    
    for(int city = 1; city <= N ; city++){
        if(!visited[city]){
            visited[city] = true;
            bridges.push_back(city); // Pongo un componente de cada conjunto de nodos
            dfs(city);
        }
    }

    // muestro la cantidad de puentes a construir
    cout << bridges.size() - 1 << endl;
    for (int bridge = 0; bridge < bridges.size() - 1; bridge++)
    {
        cout << bridges[bridge] << " " << bridges[bridge + 1] << endl;
    }

    return 0;
}