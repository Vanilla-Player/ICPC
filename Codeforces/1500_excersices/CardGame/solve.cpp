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
vector<ll>a(200005,0);

void solve(){
    ll n;
    cin >> n;
    ll sum = 0;
    a.clear();
    fori(i,n){
        ll ai;
        cin >> ai;
        a[i] = ai;
        if(ai > 0){
            sum += ai;
        }
    }
    a[n] = 0;
    ll id = 0;

    while(id < n && a[id] < 0 && id <= 1)id++;

    if(id == 1){
        
        ll ans = max(sum + a[0], sum - a[1]);
        cout << ans << "\n";
    }else{
        cout << sum << "\n";
    }

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}