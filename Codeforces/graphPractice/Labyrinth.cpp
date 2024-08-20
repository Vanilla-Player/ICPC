#include <bits/stdc++.h>

using namespace std;

// PROBLEMAS AL DEVOLVER CUANDO NO TIENE SOLUCION
// PROBLEMAS SI EL CAMINO DIFURCA MUCHO
// 5 8
// ########
// #.A#...#
// #....#B#
// #......#
// ########


vector<string> grid;
queue<pair<int,int > > q;
string visited[(int)1e3][(int)1e3];
string path = "";
int N,M;
int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};
string moves[4] = {"D","U","R","L"};


bool isValid(int x, int y) {

if (y < 0) return false;

if (x < 0) return false;

if (y >= M) return false;

if (x >= N) return false;

if (grid[x][y] == 'A') return false;

if (grid[x][y] == '#') return false;

if (visited[x][y] != "") return false;

return true;

}

string dfs(int row, int col,string movements){

    bool first  = true;
    string ans;
    for (int i = 0; i < 4; i++)
    {
        int newX = row + neighborY[i];
        int newY = col + neighborX[i];
        // cout << newX << newY << endl;
        if(isValid(newX,newY)){
            if(grid[newX][newY] != 'B'){
                if(visited[newX][newY] != ""){
                    visited[newX][newY] = min(visited[newX][newY], movements + moves[i]);
                }else{
                    visited[newX][newY] = movements + moves[i];
                }
            }else{
                return movements + moves[i];
            }
            // cout << moves[i] << endl;
            string dfspath = movements + dfs(newX,newY,moves[i]);
            

            if(first){
                ans = dfspath;
                first = false;
            }

            if(dfspath.length() < ans.length()){
                ans = dfspath;
            }
        }else{
            continue;
        }
    }
    return ans;
}


string bfs(){

    while (!q.empty())
    {
        pair<int,int> node = q.front();q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = node.first + neighborY[i];
            int newY = node.second + neighborX[i];
            if(isValid(newX,newY)){
                visited[newX][newY] = visited[node.first][node.second] + moves[i];
                if(grid[newX][newY] == 'B'){
                    return visited[newX][newY];
                }
                q.push(make_pair(newX, newY));
            }
        }   
    }
    
    return "";
    
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
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++){
            if(grid[i][j] == 'A'){
                q.push(make_pair(i,j));
                //path = dfs(i,j,"");
                break;
            }
        }
    }

    // if(path != ""){
    //     cout << "YES" << endl;
    //     cout << path.length() << endl;
    //     cout << path << endl;
    // }else{
    //     cout << "NO" << endl;
    //     cout << path.length() << endl;
    //     cout << path << endl;
    // }

    string ans = bfs();

    if(ans != ""){
        cout << "YES" << endl;
        cout << ans.length() << endl;
        cout << ans << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}