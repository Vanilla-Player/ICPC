#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(vit it = s.begin(); it != s.end(); ++it)
#define      sortAsc(v)          sort(v.begin(), v.end())
#define      sortDesc(v)          sort(v.begin(), v.end(), greater<auto>())
#define      fill(a, v)           memset(a, v, sizeof (a))

#define      fori(i, n)         for(int i = 0; i < (n); ++i)
#define      fora(i, a, n)     for(int i = a; i <= (n); ++i)
#define      ford(i, a, n)     for(int i = a; i >= (n); --i)
#define 	 pq(x)			   priority_queue<x,std::vector<x>,compare>

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

int N =1e5 + 5, n;
ll MAXIMO = 1e16;
vector<ll> distances(N,MAXIMO);
vector<bool> visited(N,false);
vector<int>adj[2505], adj2[2505];
bool vis[2505], vis2[2505];

struct Edge{
    int a , b , w;
};

void dfs(int s){
    if (vis[s]) return;
    vis[s]=1;
    for (auto i: adj[s]) dfs(i);
}
void dfs2(int s){
    if (vis2[s]) return;
    vis2[s]=1;
    for (auto i: adj2[s]) dfs2(i);
}


vector< tuple< int, int, ll> > edges; 

int main() {

    int M;
    cin >> n >> M;
    fora(i,1,M)
    {
       int node, adjc;
       ll weight;
       cin >> node >> adjc >> weight;
        edges.push_back(make_tuple(node,adjc,-weight));
        adj[node].pb(adjc), adj2[adjc].pb(node);
    }

    distances[1] = 0;
    dfs(1), dfs2(n);
    fora(i,1,n)
    {
        for (auto node : edges)
        {
            int a,b;
            ll w;
            tie(a,b,w) = node;
                if(distances[b] > distances[a]+w){
                    distances[b] = distances[a] + w;
                    if(i == n && vis[b] && vis2[b]){
                        cout << -1 << endl;
                        return 0;
                    }
                }
        }
    }
    
    cout << -distances[n] << endl;

    return 0;
}