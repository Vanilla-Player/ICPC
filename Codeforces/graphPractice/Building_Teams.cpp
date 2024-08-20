#include <bits/stdc++.h>

using namespace std;

int MAX_N = 1e5 + 1;
int visited[(int)1e5 + 1];
vector<vector<int > > adj(MAX_N); 
vector<int > teams;
int N,M;

// 5 4
// 1 2
// 1 3
// 1 4
// 4 5
//
void dfs(int node){


    for(int child: adj[node]){
        if(visited[child]){
            if(teams[node - 1] == teams[child - 1]){
                teams[0] = 0;  
                return;
            }

            continue;
        } 
        // node - 1 because first node is 1, index of teams is offset - 1
        if(teams[node - 1] == 1){
            teams[child - 1] = 2;
        }else{
            teams[child - 1] = 1;
        }

        visited[child] = 1;
        dfs(child);
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {   
        int friend1, friend2;
        cin >> friend1 >> friend2;
        adj[friend1].push_back(friend2);
        adj[friend2].push_back(friend1);
    }

    for (int i = 0; i < N; i++)
    {
        teams.push_back(0);
    }
    

    for (int i = 1; i <= N; i++)
    {
        if(!visited[i]){
            visited[i] = 1;
            teams[i - 1] = 1;
            dfs(i);
            if(teams[0] == 0){
                break;
            }
        }
    }
    
    if(teams[0] != 0){

    for (int i = 0; i < teams.size() - 1; i++)
    {
        cout << teams[i] << " ";
    }
    cout << teams[teams.size() - 1];
    
    }else{
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}