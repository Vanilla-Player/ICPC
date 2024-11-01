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
const ll INF = 1000000000000000000LL;


vector<vector<ii> > adj(MAXN);
int n,m,k;
ll d[MAXN];
int visited[MAXN];
int train_to_use = 0;


struct Vertex{
    int v,state;
    ll w;
    bool operator < (const Vertex &o) const {
    if (w != o.w)
      return w > o.w;
    if (state != o.state)
      return state > o.state;
    return v > o.v;
  }
};
priority_queue<Vertex>q;

void dijkstra(int s){

    fora(i,1,n)d[i] = INF;
    
    d[s] = 0;
    
    Vertex first;
    first.v = s;
    first.state = 0;
    first.w = 0;

    q.push(first);
    
    while(!q.empty()){
        Vertex from = q.top();
        q.pop();
        // dprint(from.v);
        if(visited[from.v])continue;
        visited[from.v] = 1;
        d[from.v] = from.w;

        if(from.state == 1){
            train_to_use++;
        }
        // dprint(from);
        
        
        for(auto v: adj[from.v]){
            int to = v.se;ll w = v.fi;

            if(d[from.v]+w < d[to]){
                d[to] = d[from.v]+w;
                Vertex to_add;
                to_add.v = to;
                to_add.w = d[to];
                to_add.state = 0;
                q.push(to_add);
            }
        }

    }
}

int main(){
    cin >> n >> m >> k;
    fori(i,m){
        int from, to;
        ll w;
        cin >> from >> to >> w;
        adj[from].pb(mp(w,to));
        adj[to].pb(mp(w,from));
    }

    fori(i,k){
        int city;
        ll w;
        cin >> city >> w;
        Vertex to_add;
        to_add.v = city;
        to_add.state = 1;
        to_add.w = w;
        q.push(to_add);
    }
    Vertex e = q.top();
    // dprint(e.v);
    // dprint(e.state);
    // dprint(e.w);

    dijkstra(1);

    cout << k - train_to_use << "\n";
}