#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
typedef __uint128_t u128;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
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



struct comp {
    bool operator() (const ii& a, const ii& b) const {
        return a.second < b.second; // Compare based on the second element
    }
};

void solve(){
    int n;
    cin >> n;
    vector<ii>people;
    vector<ll>ends;
    set<ii>ends_starts;
    map<ii,int>indx;
    fori(i,n){
        ll x, y;
        cin >> x >> y;
        people.pb(mp(x,y));
        // starts.insert(x);
        ends_starts.insert(mp(y,x));
        
    }

    sort(all(people));
    fori(i,n){
        indx[people[i]] = i;
    }
    cout << "Order\n";
    for(auto p : people){
        cout << p.fi << " " << p.se << "\n";
        cout << "INDEX: " << indx[{p.fi,p.se}] << "\n";
    }
    ll ans = 0;
    fori(i,n){
        ii p = people[i]; 
        ll e = p.se; 
        // dprint(e);
        auto pe = prev(ends_starts.lower_bound({p.se,p.fi}));
        ll x,y;
        x = pe->se;
        y = pe->fi;
        // dprint(x);
        // dprint(y);
        int posf = indx[{x,y}];
        // dprint(posf - i);
        ans += posf - i > 0?posf - i: 0;
        // ans+= distance(ends.begin(),pe);
        ends_starts.erase({p.se,p.fi});
    }   
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >>t;
    
    while(t--){
        solve();
    }
}