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

const int MAXN = 10005;

ll len[MAXN];

int parent[MAXN];
int special[MAXN];

int n,m,k;

int find(int x){
    while(x != parent[x]) x = parent[x];
    return x;
}

ll calc(int x){
    return x*(x-1)/2;
}

int main(){
    cin >> n >> m >> k;

    fori(i,k){
        cin >> special[i];
    }

    fori(i,n + 1){
        parent[i] = i;
    }


    fori(i,m){
        int u,v;
        cin >> u >> v;
        u = find(u);
        v = find(v);
        parent[u] = v;
    }

    fori(i,n){
        len[find(i+1)]++;
    }
    ll sum = 0;
    int isolated = n;
    ll largest = 0;
    fori(i,k){
        
        int king = find(special[i]);
        
        largest = max(largest,len[king]);
        sum += calc(len[king]);
        isolated -= len[king];

    }

    sum -= calc(largest);
    sum += calc(largest + isolated);
    sum -= m;

    cout << sum << "\n";
    return 0;


}
