#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
typedef __uint128_t u128;
typedef long long ll;
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
// Si lleva ")" al final

#define EPS 1e-9


struct pto{
ll x, y;
pto(ll x=0, ll y=0):x(x),y(y){}
pto operator+(pto a){return pto(x+a.x, y+a.y);}
pto operator-(pto a){return pto(x-a.x, y-a.y);}
pto operator+(ll a){return pto(x+a, y+a);}
pto operator*(ll a){return pto(x*a, y*a);}
pto operator/(ll a){return pto(x/a, y/a);} //dot product, producto interno:
ll operator*(pto a){return x*a.x+y*a.y;}
ll operator^(pto a){return x*a.y-y*a.x;}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;} ld norm(){return sqrt(x*x+y*y);}
ll norm_sq(){return x*x+y*y;}
};

void solve(){
    ll n;
    cin >> n;
    vector<ll> xs(n + 1);
    map<pair<ll,ll>, ll> map_points;
    vector<ii>points;
    fori(i,n){
        ll x,y;
        cin >> x >> y;
        points.pb(mp(x,y));
        map_points[mp(x,y)] = 1;
        xs[x]++;
    }

    ll ans = 0;

    for(auto x: xs){
        if(x == 2)ans+=n-2;
    }

    for(auto p: points){
        if((map_points[mp(p.fi-1,p.se^1)])&& (map_points[mp(p.fi+1,p.se^1)])){
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}