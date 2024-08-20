#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
int visited[(int)1e3][(int)1e3];
int rooms = 0;
int N,M;

void dfs(int row, int col, char c){

    if(row >= N || col >= M){
        return;
    }
    if(row < 0 || col < 0){
        return;
    }

    if(visited[row][col] == 1) return;
    visited[row][col] = 1;


    if(c == '#' && grid[row][col] == '.'){
        rooms += 1;
    }
    
    dfs(row+1, col, grid[row][col]);
    dfs(row, col+1, grid[row][col]);
    dfs(row-1, col, grid[row][col]);
    dfs(row, col-1, grid[row][col]);


}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {   
        string row;
        cin >> row;
        grid.push_back(row);
    }
    dfs(0,0,grid[0][0]);

    cout << rooms << endl;

    return 0;
}