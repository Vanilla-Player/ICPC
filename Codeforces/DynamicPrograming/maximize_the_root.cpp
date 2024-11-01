#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define fori(i,n) for(int i = 0; i < (n);i++)
#define fora(i,a,n) for(int i = (a); i <= (n);i++)

#define fill(a, v) memset(a, (long long)v, sizeof(a))
#define oper max
#define int long long
const int INF = 1e9 + 7;
const int MAXN = 200005;

int t, n;
vector<vector<int> > adj;
int dp[MAXN];
int vertex[MAXN];

int dfs(int n, int f){
    
    // cout << "node: " << n << "\n";

    for(auto v: adj[n]){
        // cout << "Go" << endl;
        dp[n] = min(dfs(v,n),dp[n]);
        
    }
    // cout << "Ans" << endl;
    // cout << "dp => " << n << " = " << dp[n] << endl;
    if(f == 0 || dp[n] <= vertex[n]){ // Important statement dp[n] <= vertex[n]
        return dp[n];
    }

    if(dp[n] >= INF ){
        return vertex[n];
    }

    if(dp[n] == 0){
        return 0;
    }


    int ans =  (dp[n]+vertex[n])/2; 
    if(ans == 0 && vertex[n]!= 0){
        return 1;
    }
    return ans;
    

}


void solve(){

    cin >> n;
    
    adj = vector<vector<int> > (n + 1);
    fill(dp, INF);
    fill(vertex, 0);
    fora(i,1,n){
        cin >> vertex[i];
    }

    fora(to,2,n){
        int from;
        cin >> from;
        adj[from].push_back(to);
    }
    vertex[1]+= dfs(1,0);
    cout << vertex[1] << endl;

}


signed main(){

    cin >> t;

    while(t--){
        solve();
    }
}