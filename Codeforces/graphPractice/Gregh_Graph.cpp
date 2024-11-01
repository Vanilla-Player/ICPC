#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
typedef long long ll;
typedef __uint128_t u128;
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

ll g[505][505];
ll sums[505];
ll used[505], q[505];
ll n;


void solve(){
    cin >> n;
    fora(i,1,n){
        fora(j,1,n){
            ll w;
            cin >>w;
            g[i][j] = w;
        }
    }



    fori(i,n){
        cin >> q[i];
    }
    sums[n-1] = 0;
    fill(used,0);
    ford(kk, n-1,0){
        sums[kk] = 0;
        ll k = q[kk];
        used[k] = 1;
        // dprint(kk);
        // dprint(k);

        fora(i,1,n){
            fora(j,1,n){
                if(g[i][k] + g[k][j] < g[i][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }

        fora(i,1,n){
            fora(j,1,n){
                if(used[i] && used[j]) sums[kk] += g[i][j];
            }
        }

    }

    fori(i,n){
        cout << sums[i] << " ";
    }
    cout << "\n";return;

}


int main(){
    solve();
}