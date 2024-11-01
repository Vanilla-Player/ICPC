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
    cin >> n;
    int a[n+1];
    int deg[n+1];
    ll ans =0;
    fora(i,1,n){
        cin >> a[i];
        ans += a[i];
        deg[i] = 0;
    }

    fori(i,n - 1){
        int from,to;
        cin >> from >> to;
        deg[from]++;deg[to]++;
    }

    vector<int>best_w;
    fora(i,1,n){
        fora(j,1,deg[i] - 1){
            best_w.pb(a[i]);
        }
    }
    sort(all(best_w),greater<int>());
    cout << ans << " ";
    
    for(auto b :best_w ){
        ans+=b;
        cout << ans << " ";
    }
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}