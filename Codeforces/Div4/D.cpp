#include <bits/stdc++.h>
#define ll long long 

using namespace std;
vector<string > grid;
int x = 0,y = 0;
int H,W;


void dfs(int row, int col){

    bool end = true;
    int count = 0;
    while (end)
    {
        if(row + count + 1 >= H){
            end = false;
            continue;
            }
        if(grid[row+ count +1][col] != '#') {
            end = false;
            continue;
        }
        count++;
    }
    if(count != 0){
        count = (count/2);
    }
    x = row + count;
    y = col;
    
}

int main(){

    int t;
    cin >> t;

    while (t--)
    {
        
        cin >> H >> W;
        for (int i = 0; i < H; i++)
        {
            string row;
            cin >> row;
            grid.push_back(row);
            
        } 
        
        bool solve = false;
        for (int row = 0; row < H; row++)
        {
            for (int col = 0; col < W ; col++)
            {
                if(grid[row][col] == '#'){
                    if(!solve){
                        dfs(row,col);
                        cout << x+1 << " " << y+1 << endl;
                        solve = true;
                    }

                }
            }   
        }

        x = 0;
        y = 0;
        grid.clear();

    }
    
    



    return 0;
}