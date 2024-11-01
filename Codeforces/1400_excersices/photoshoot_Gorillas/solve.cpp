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

#define MAXW 200200
#define MAXNM 200200

ll n,m,w,k;
ll arr[MAXW];
ll prr[MAXNM];


ll calc(ll i, ll j){
    ll upr = min(i, n - k);
    ll leftr = min(j,m-k);
    ll upl = max(-1LL, i - k);
    ll leftl = max(-1LL, j-k);

    return (upr-upl)*(leftr - leftl);
}

void build(){
    
    ll id = 0;
    fori(i,n){
        fori(j,m){
            prr[id++] = calc(i,j);
        }
    }

    sort(prr, prr + id);
    reverse(prr, prr + id);
    
}

void solve(){
    
    build();
    sort(arr,arr + w);
    reverse(arr,arr + w);
    ll ans = 0;
    fori(i,w){
        ans += prr[i]*arr[i];
    }
    cout << ans << endl;

}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k >> w;
        fori(i,w){
            cin >> arr[i];
        }
        solve();
    }
    
}
