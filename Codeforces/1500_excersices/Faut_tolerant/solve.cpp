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
const ll INF = 1e10;

vector<ll>a;
vector<ll>b;
ll n;

ll best_candidate(const vector<ll>vals,ll cur){

    ll best = INF; ll pos = -1;
    fori(i,n){
        if(best > abs(vals[i]-cur)){
            pos = i;
            best = abs(vals[i]-cur);
        }
    }

    return pos;
}

void solve(){

    cin >> n;
    a.resize(n);
    b.resize(n);
    fori(i,n){
        cin >> a[i];
    }
    fori(i,n){
        cin >> b[i];
    }

    vector<ll> candidates1 = {0,best_candidate(b,a[0]),n-1};
    vector<ll> candidates2 = {0,best_candidate(b,a[n-1]),n-1};
    ll mini = 1e12;
    for(auto c1 :candidates1){
        for(auto c2 :candidates2){
            ll ans = (ll)abs(a[0] - b[c1]) + (ll)abs(a[n-1]-b[c2]);

            if(c1 > 0 && c2 > 0){
                ans+= (ll)abs(b[0] - a[best_candidate(a,b[0])]);
            }
            if(c1 < n-1 && c2 < n-1){
                ans += (ll)abs(b[n-1] - a[best_candidate(a,b[n-1])]); 
            }

            mini = min(mini,ans);
        }
    }

    cout << mini << "\n";
    

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}