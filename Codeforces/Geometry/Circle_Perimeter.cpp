    #include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
typedef __uint128_t u128;
typedef long long ll;
typedef long double ld;
// typedef pair<int, int> ii;
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
// Si lleva ")" al final

#define EPS 1e-9


void solve(){
    ll r;
    cin >> r;
    ll tot = 0;
    for (ll i = 1; i <= r; i++){
        // assert(i!=r);
        ll rr = r*r;
        ll rpr = (r+1)*(r+1);
        ll ii = 1LL*(i*i);
        
        ll sub = ceil(sqrt(rr - ii));
        ll add = ceil(sqrt(rpr - ii));
        tot += add - sub;
    }
    cout << tot * 4 << '\n';
    // 2r > x^2 - 1;

    
    

}

int main(){
    ios::sync_with_stdio(false);
  cin.tie(0);   
    int t;
    cin >> t;
    while(t--){
        solve();

    }
}