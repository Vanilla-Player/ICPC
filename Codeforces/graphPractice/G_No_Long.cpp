#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
typedef long long ll;
typedef __uint128_t u128;
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

const int MAXN = 200005;

bool bipartite;
vector<int>color;
vector<vector<int> > adj(MAXN);
vector<ii> edges;

void dfs(int n, int c){
    color[n] = c;

    for(auto v: adj[n]){

        if(color[v] == -1){
            dfs(v, c^1);
        }else{
            if(color[v] == color[n]){
                bipartite = false;
            }
        }

    }
}

int main(){
    int n, m;
    cin >> n >> m;

    fori(i,m){
        int from, to;
        cin >> from >> to;
        adj[from].pb(to);
        adj[to].pb(from);
        edges.pb(mp(from,to));
    }

    color = vector<int>(n+1,-1);
    bipartite = true;

    dfs(1,0);

    if(!bipartite){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for(auto e : edges){
        cout << (color[e.fi] < color[e.se]);
    }
    cout << "\n";

}

