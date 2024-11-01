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

void solve(){

    int n;
    cin >>n;
    map<ll,ll>v,h,d1,d2;
    fori(i,n){
        ll x,y;
        cin >> x >> y;
        v[y]++;
        h[x]++;
        d1[x+y]++;
        d2[x-y]++;
    
    }
    ll ans = 0;
    for(auto x: v){
        ans += x.se*(x.se-1);
    }
    for(auto x: h){
        ans += x.se*(x.se-1);
    }
    for(auto x: d1){
        ans += x.se*(x.se-1);
    }
    for(auto x: d2){
        ans += x.se*(x.se-1);
    }
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}