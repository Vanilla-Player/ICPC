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

const int MAXN = 100005;


ll len[MAXN];

int n, m;
int parent[MAXN];

int visited[MAXN];



vector<tuple<ll,int,int> > edges; 

int find(int x){
    while(x != parent[x]) x = parent[x];
    return x;
}

void unite(int a, int b){
    if (find(a)==find(b)) return;
    int x = find(a), y = find(b);
    if (len[x]>len[y]) swap(x,y);
    len[y]+=len[x];
    parent[x] = y;
}


int main(){

    cin >> n >> m;

    fori(i,n+1){
        parent[i] = i;
        len[i] = 1;
    }

    fori(i,m){
        ll a,b,w;
        cin >> a >> b >>w;
        edges.pb({w,a,b});
    }

    sort(all(edges));

    ll ans = 0;
    for (auto [w,a,b]:edges){
        if (find(a)==find(b)) continue;
        ans+=w;
        // cout << "UNITE\n";
        // dprint(a);
        // dprint(b);
        unite(a,b);
    }

    int comps = 0;
    fora(i,1,n){
        if(parent[i] == i){
            comps++;
            // dprint(i);
            }

        }
    // dprint(comps);
    if(comps == 1)cout << ans <<"\n";
    else cout << "IMPOSSIBLE\n";
    
    return 0;   

}