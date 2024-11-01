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

const int MAXN = 61;
const int MOD = 998244353;
ll F[61];
ll inv[61];
ll rF[61];


ll calc(ll n, ll k){
    return (F[n] * rF[k] % MOD * rF[n-k] % MOD);
}

ll play(ll n,ll id){
    if (n == 2){
        // dprint(id);
        if(id == 1){
            return 1;
        }else{
            return 0;
        }
    }

    if(id == 1){
        ll a = play(n-2,1^id);
        return calc(n-1,n/2) + a;
    }else{
        ll a = play(n-2,1^id);
        // dprint(n);
        // dprint(n-2);
        return calc(n-2,n/2) + a;
    }
}


void solve(){

    int n;
    cin >> n;
    // cout << "ALICE\n";
    ll a = play(n,1);
    // cout << "Boris\n";
    ll b = play(n,0);

    cout << a%MOD << " " << b%MOD << " " << 1 << "\n";
    
}

int main(){

    F[0] = rF[0] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAXN; i++) {
	inv[i] = MOD - (long long)(MOD/i)*inv[MOD%i]%MOD; // Se usa el MOD - PORQUE -X = (MOD-X) EN ARITMETICA MODULAR
    }
    for (int i = 1; i < MAXN; i++) { // Factoriales
        F[i] = F[i-1] * i % MOD;
        rF[i] = rF[i-1] * inv[i] % MOD;
    }

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}