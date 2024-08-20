#include <bits/stdc++.h>
#define ll long long  

using namespace std;

vector<string> grid;
int visited[2001][2001];
int H, W;
int rosarios = 0;

// 4 7
// .*...*.
// ***.***
// .*...*.
// .*...*.

void solve(int row, int col){
    int contL = 0;
    int contR = 0;
    int contU = 0;
    int contD = 0;

    int offset = 1;
    while (col - offset >= 0) // count left
    {
        if(grid[row][col - offset] != '*')break;
        if(visited[row][col-offset]){
            return;
        }
        visited[row][col-offset] = 1;
        if(grid[row+1][col - offset] != '.') return;
        if(grid[row-1][col - offset] != '.') return;
        contL++;
        offset++;
    }

    offset = 1;
    while (col + offset < W) // count right
    {
        if(grid[row][col + offset] != '*')break;
        if(visited[row][col+offset]){
            return;
        }
        visited[row][col+offset] = 1;
        if(grid[row+1][col + offset] != '.') return;
        if(grid[row-1][col + offset] != '.') return;
        contR++;
        offset++;
    }

    offset = 1;
    while (row - offset >= 0) // count Up
    {
        if(grid[row - offset][col] != '*')break;
        if(visited[row - offset][col]){
            return;
        }
        visited[row - offset][col] = 1;
        if(grid[row - offset][col + 1] != '.')return;
        if(grid[row - offset][col - 1] != '.')return;
        contU++;
        offset++;
    }

    offset = 1;
    while (row + offset < H ) // count Down
    {
        if(grid[row + offset][col] != '*')break;
        if(visited[row + offset][col]){
            return;
        }
        visited[row + offset][col] = 1;
        if(grid[row + offset][col + 1] != '.')return;
        if(grid[row + offset][col - 1] != '.')return;
        contD++;
        offset++;
    }

    // cout << "ARRIBA" << endl;
    // cout << contU << endl;
    // cout << "ABAJO" << endl;
    // cout << contD << endl;
    // cout << "DERECHA" << endl;
    // cout << contR << endl;
    // cout << "IZQUIERDA" << endl;
    // cout << contL << endl;

    if(contU == 0) return;    
    if(contU != contR)return;
    if(contR != contL)return;
    if (contD <= contL)return;

    rosarios++;

}

int main(){

    cin >> H >> W;

    for (int i = 0; i < H; i++)
    {
        string row;
        cin >> row;
        grid.push_back(row);
    }
    
    for (int row = 0; row < H; row++)
    {
        for (int col = 0; col < W; col++)
        {
            if(visited[row][col]){
                continue;
            }
            if(grid[row][col] != '*'){
                continue;
            }
            if(row - 1 < 0 || row + 1 >= H ){
                continue;
            }
            if(col - 1 < 0 || col + 1 >= W){
                continue;
            }
            if(grid[row][col + 1] != '*' || grid[row][col - 1] != '*'){
                continue;
            }
            if(grid[row + 1][col] != '*' || grid[row + 1][col] != '*'){
                continue;
            }
            visited[row][col] = 1;
            solve(row,col);
        }
        
    }
    
    cout << rosarios << endl;

    return 0;
}