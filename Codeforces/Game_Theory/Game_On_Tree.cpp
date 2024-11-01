#include <bits/stdc++.h>
const int MAXN = 200050;
using namespace std;

vector<int> graphinho[MAXN];
int g[MAXN];

int n,t;

void dfs(int n, int f){
    g[n] = 0;
    for(auto v: graphinho[n]){
        // cout << "INF" << endl;
        if(v == f)continue;
        dfs(v,n);
        if(!g[v])g[n] = 1;
    }

}

int main(){

    cin >> n >> t;

    for (int i = 1; i <= n - 1; i++)
    {
        int from, to;
        cin >> from >> to;
        graphinho[from].push_back(to);
        graphinho[to].push_back(from);
    }

    int u;
    cin >> u;
    dfs(u,-1);
    if(g[u]){
        cout << "Ron" << endl;
    }else{
        cout << "Hermione" << endl;
    }

}