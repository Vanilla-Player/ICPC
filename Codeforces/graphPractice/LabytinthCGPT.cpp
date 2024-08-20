#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
string visited[(int)1e3][(int)1e3];
string path = "";
int N, M;
int neighborX[4] = {-1, 0, 1, 0};
int neighborY[4] = {0, -1, 0, 1};
char moves[4] = {'R', 'L', 'D', 'U'};

bool isValid(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M || grid[x][y] == '#' || grid[x][y] == 'A' || !visited[x][y].empty()) return false;
    return true;
}

bool dfs(int x, int y, string movements) {
    if (grid[x][y] == 'B') {
        path = movements;
        return true;
    }
    
    visited[x][y] = movements;
    
    for (int i = 0; i < 4; ++i) {
        int newX = x + neighborX[i];
        int newY = y + neighborY[i];
        if (isValid(newX, newY)) {
            if (dfs(newX, newY, movements + moves[i])) {
                return true;
            }
        }
    }
    
    visited[x][y] = ""; // Unmark this cell as visited for other paths
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    grid.resize(N);
    
    pair<int, int> start;
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'A'){
              start.first = i ;  
              start.second = j;  
            } 
        }
    }
    
    if (dfs(start.first, start.second, "")) {
        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
