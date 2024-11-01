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


const int MAXN = 1005;

vector<tuple<int,int,int> > edges;

int has_sup[MAXN];
int slave[MAXN];
int parent[MAXN];
ll len[MAXN];

int find(int x){
    while(x != parent[x]) x = parent[x];
    return x;
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b)return;
    if(len[a]> len[b]) swap(a,b);
    len[b] += len[a];
    parent[a] = b;
}

int main(){

    int n;
    cin >> n;
    fori(i,n){
        len[i+ 1] = 1;
        parent[i + 1] = i+1;
    }

    fori(i,n){
        int s;
        cin >> s;
    }

    int m;
    cin >> m;

    fori(i,m){
        int sup,slv,w;
        cin >> sup >> slv >> w;
        slave[slv]++;
        edges.pb({w,sup,slv});
    }

    int cnt = 0;
    fori(i,n){
        if(slave[i+1])cnt++;
    }

    if(n - cnt > 1){
        cout << -1 << "\n" ;
        return 0;
    }
    sort(all(edges));
    
    ll ans = 0;
    for(auto [w,a,b]:edges){
        // dprint(a);
        // dprint(b);
        // dprint(w);

        if(find(a) == find(b))continue;
        if(has_sup[b])continue;
        has_sup[b] = 1;
        ans+=w;
        unite(a,b);
    }

    cout << ans << "\n";

}

