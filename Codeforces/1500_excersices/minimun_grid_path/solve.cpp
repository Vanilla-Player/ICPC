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

const ll INF = 1e9;

void solve(){

    ll n;
    cin >> n;
    ll a[n+1];
    fora(i,1,n){
        cin >> a[i];
    }
    ll minOdd = a[1];
    ll minEven = INF;
    ll sum = a[1];
    ll ans = 1e18;
    fora(i,2,n){
        if(i%2){
            minOdd = min(a[i],minOdd);
        }else{
            minEven = min(a[i], minEven);
        }
        sum+=a[i];
        ans = min(ans, sum + (n-(i+1)/2)*minOdd + (n-i/2)*minEven);
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