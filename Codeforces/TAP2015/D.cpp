#include <bits/stdc++.h>
#define MAXN 1e3 + 2

using namespace std;


bool visited[(int)MAXN];
int N,M,R,E;
vector<int > adj[(int)1e3 + 2];
int cities = 0;
int estadiumCost = 0;
int routes = 0;
int routesCost = 0;
int cost = 0;

void dfs(int node){
    cities++;
    for (auto child: adj[node])
    {
        if(visited[child])continue;
        routes++;
        visited[child] = true;
        dfs(child); 
        
    }
    

}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> N >> M >> R >> E){
        for (int row = 1; row <= M; row++)
        {
            int node1,node2;
            cin >> node1 >> node2;
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        
        for(int city = 1; city <= N ; city++){
            if(!visited[city]){
                visited[city] = true;
                dfs(city);
                routesCost = (((cities*(cities - 1))/2) - (routes))*R;
                estadiumCost = cities*E;
                
                if(routesCost < estadiumCost ){
                    cost += routesCost;
                }else{
                    cost += estadiumCost;
                }
                cities = 0;
                routes = 0;
                estadiumCost = 0;
                routesCost = 0;
            }


        }
            
        cout << cost << '\n';
        cost = 0;
        for (int i = 0; i <=  N; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i <=  N; i++)
        {
            adj[i].clear();
        }
        

    }


    return 0;
}