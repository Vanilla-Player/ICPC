#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

// Metodos para vectores, sets y maps
#define each(it, s) for (vit it = s.begin(); it != s.end(); ++it)
#define sortAsc(v) sort(v.begin(), v.end())
#define sortDesc(v) sort(v.begin(), v.end(), greater<auto>())
#define fill(a, v) memset(a, v, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

// Iterar
#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

#define fi first
#define se second
#define mp make_pair
#define pb push_back

// Para printear Variables
#define  dprint(v) cout << #v"=" << v << endl //;) 
// Si lleva ")" al final

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;


ll target;
vector<ll> sequence;
vector<ll> dp;
vector<bool>used;
vector<vector<int> >p_recipe;


ll dfs(ll n){

    if(used[n]){
        return dp[n];
    }
    used[n] = true;

    ll cost = 0;
    for(auto p: p_recipe[n]){
        cost += dfs(p);
    }

    if(!p_recipe[n].empty()){
        if(dp[n] > cost){
            dp[n] = cost;
        }
    }
    
    return dp[n];
}

void solve(){

    ll n, k;
    cin >> n >> k;
    dp.resize(n);
    used.assign(n,false);
    p_recipe.assign(n, vector<int>(0));
    fori(i,n){
        cin >> dp[i];
    }

    // cout << "Start Costs" << endl;

    //  fori(i,n){
    //     cout << dp[i] << " ";
    // }
    // cout <<"\n";

    fori(i,k){
        int pot;
        cin >> pot;
        pot--;
        dp[pot] = 0;
    }

    // cout << "UPDATED COSTS" << endl;
    //  fori(i,n){
    //     cout << dp[i] << " ";
    // }
    // cout <<"\n";
    

    fori(i,n){
        int m;
        cin >> m;
        p_recipe[i].resize(m);
        fori(j,m){
            int pot;
            cin >> pot;
            pot--;
            p_recipe[i][j] = pot;
        }
    }
    // cout << "Recipes" << endl;
    // fori(i,n){
    //     for(auto pot: p_recipe[i]){
    //         cout << pot << " ";
    //     }
    //     cout <<"\n";
    // }
    

    fori(i,n){
        dfs(i);
    }

    // cout << "ANS" << endl;
    fori(i,n){
        cout << dp[i] << " ";
    }
    cout <<"\n";
    return;
    
}


int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;   
    while(t--){
        solve();
    }
    return 0;

}