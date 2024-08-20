#include <bits/stdc++.h>
#define MAXN 202020

using namespace std;


queue<int> q;
vector<vector<int> > visited(MAXN);
int N,M;
vector<vector<int> > adj(MAXN);
int ans = 1e5 + 1;
vector<int > path;

// 5 6
// 1 2
// 1 3
// 1 4
// 2 3
// 3 5
// 5 4

// void dfs(int node,int routers, vector<int> currentPath){

//     // cout << "NODE" << endl;
//     // cout << node << endl;
//     // cout << "Routers" << endl;
//     // cout << routers << endl;

//     for (int child: adj[node])
//     {
//         if(child == N){
//             int currentRouters = routers + 1;
//             if(ans > currentRouters){
//                 currentPath.push_back(child);
//                 path = currentPath;
//                 ans = currentRouters;
//                 currentPath.pop_back();    
//             }
//         }

//         if(visited[child])continue;
//         visited[child] = true;

//         currentPath.push_back(child);
//         dfs(child, routers + 1, currentPath);
//         currentPath.pop_back();
//     }

// }

vector<int> bfs(){

    while (!q.empty())
    {
        int node = q.front();q.pop();

        for (int edge: adj[node])
        {   
            if(!visited[edge].empty())continue;

            visited[edge] = visited[node];
            visited[edge].push_back(node);

            if(edge == N){
                visited[edge].push_back(edge);
                return visited[edge];
            }

            q.push(edge);
        }
        

    }
    vector<int > empty;
    return empty;

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
    
    q.push(1);

    vector<int > ans = bfs();
    if(!ans.empty()){
        int size = ans.size();
        cout << size << endl;
        for (int i = 0; i < size - 1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << ans[size - 1];
        
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    // vector<int> dfsPath;
    // dfsPath.push_back(1);
    //dfs(1,1, dfsPath);

    // muestro la cantidad de puentes a construir
    // if(ans < 1e5 + 1){
    //     cout << ans << endl;
    //     for (int i = 0; i < path.size() - 1; i++)
    //     {
    //         cout << path[i] << " ";
    //     }
    //     cout << path[path.size() - 1];
        
    // }else{
    //     cout << "IMPOSSIBLE" << endl;
    // }

    return 0;
}