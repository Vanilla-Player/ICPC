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

const ll MOD = 998244353;
const ll INF = 1e18;

void solve(){

    string s;
    cin >> s;
    
    ll n = s.size();
    ll len = 0;ll er = 0;
    ll res = 1;

    fora(i,1,n-1){

        if(s[i] == s[i-1]){
            len ++;
            er++;
        }else{
            res = (res*(len+1))%MOD;
            len =0;
        }
    }
    res = (res*(len+1))%MOD;

    fora(i,1,er){
        res = (res*i)%MOD;
    }

    cout << er  << " " << res << "\n";

}


int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }

}