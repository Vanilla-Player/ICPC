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
    int n;
    cin >> n;
    vector<pto>circles;
    fori(i,n){
        ll x,y;
        cin >> x >> y;
        pto p(x,y);
        circles.pb(p);
    }

    ll xo, yo, xf, yf;
    cin >> xo >> yo >> xf >> yf;
    pto po(xo,yo);
    pto pf(xf,yf);
    pto pt = pf - po; 
    ll dt = pt.norm_sq(); 
    bool touched = false;
    // dprint(dt);  
    fori(i,n){
        pto pc = pf - circles[i];
        ll dc = pc.norm_sq();
        // assert(dc <= 1e18);
        // cout << "OP: " << i << "\n";
        // dprint(dc);
        if(dc <= dt){
            touched = true;
            break;
        }

    }
    if(touched){
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}