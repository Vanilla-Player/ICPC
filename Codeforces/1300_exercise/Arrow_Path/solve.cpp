#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define fori(i,n) for(int i = 0; i < (n); i++)
#define fora(i,a,n) for(int i = (a); i <= (n); i++)
#define ford(i,a,n) for(int i = (a); i >= (n); i++)

#define pb push_back
#define mp make_pair

#define dprint(v) cout << #v"=" << v << endl //;)


vector<int>dx = {0,1,0,-1};
vector<int>dy = {1,0,-1,0};
vector<vector<int>>visited;
int n;
vector<string>g;
bool possible(int x, int y){
    // cout << "Intento\n";
    if(x < 2 && x >= 0 && y < n && y >= 0){
        // cout << "paso\n";
        return true;
    }
    // cout << "No paso\n";

    return false;
}

void dfs(int x, int y){

    fori(i,4){


        // cout << "S1\n";
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        // cout << "Cons\n";
        // dprint(nx);
        // dprint(ny);
        if(!possible(nx,ny))continue;
        
        if(g[nx][ny] == '<'){
            ny--;
        }else{
            ny++;
        }
        // cout << "-----------------\n";
        // cout << "---NOW----\n";
        // dprint(nx);
        // dprint(ny);
        // cout << "---End----\n";
        if(visited[nx][ny])continue;
        // cout << "S2\n";
        visited[nx][ny] = 1;
        dfs(nx,ny);
    }

}


void solve(){
    cin >>n;
    g = vector<string>(2);
    visited = vector<vector<int>>(2,vector<int>(n,0));
    fori(i,2){
        cin >> g[i];
    }

    visited[0][0] = true;
    dfs(0,0);
    cout << (visited[1][n-1]? "Yes\n" : "No\n");
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}