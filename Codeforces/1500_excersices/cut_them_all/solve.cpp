#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable

typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;


#define ll long long

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

const int MAXN = 200005;
int n;

vector<vector<int> > adj(MAXN);
vector<int> sub(MAXN,0);
int ans = 0;

void dfs(int node, int p){
    sub[node] = 1;
    for(auto v : adj[node]){
        if(v == p)continue;

        dfs(v,node);
        if(sub[v]%2 == 0){
            ans++;
        }else{
            sub[node]+=sub[v];
        }
    }
}

int main(){
    cin >> n;
    fori(i,n - 1){
        int from,to;
        cin >> from >> to;
        adj[from].pb(to);
        adj[to].pb(from);
    }

    if(n%2){
        cout << -1 << "\n";
        return 0;
    }

    dfs(1,-1);


    cout << ans <<"\n";

}