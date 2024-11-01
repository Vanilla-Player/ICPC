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

const int MAXN = 100050;
const ll INF = 1e18;


vector<vector<ii> > adj(MAXN);
int n,m;
ll d[MAXN];
int p[MAXN];
int visited[MAXN];

void printPath(int s, int f){

    if(d[f] >= INF){
        cout << "-1" <<"\n";
        return;
    }

    vector<int>path;
    for(int i = f; s != i; i = p[i]){
        // cout << "inf\n";
        path.pb(i);
    }
    path.pb(s);
    reverse(rall(path));

    for(auto v: path){
        cout << v << " ";
    }
    cout << "\n";

    return;
}

void dijkstra(int s){

    fora(i,1,n)d[i] = INF;
    fora(i,1,n)p[i] = -1;
    d[s] = 0;
    priority_queue<ii>q;
    q.push(mp(0,s));
    
    while(!q.empty()){
        int from = q.top().se;
        ll weight = q.top().fi;
        q.pop();
        if(visited[from])continue;
        visited[from] = 1;
        d[from] = weight;
        // dprint(from);

        
        
        for(auto v: adj[from]){
            int to = v.se;ll w = v.fi;
            // dprint(to);
            // dprint(w);
            // dprint(d[to]);
            if(d[from]+w < d[to]){
                // cout << "ASSIGN\n";
                d[to] = d[from]+w;
                // dprint(d[to]);
                p[to] = from;
                q.push({-d[to],to});
            }
        }

    }
}

int main(){
    cin >> n >> m;
    fori(i,m){
        int from, to, w;
        cin >> from >> to >> w;
        adj[from].pb(mp(w,to));
        adj[to].pb(mp(w,from));
    }

    dijkstra(1);
    printPath(1,n);


}