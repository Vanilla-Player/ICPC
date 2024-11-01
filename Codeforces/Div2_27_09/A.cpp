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

const int MAXN = 100005;

void solve(){

    int n;
    vector<int>arro;
    vector<int>arre;
    cin >> n;
    int maxio = 0;
    int maxie = 0;
    fori(i,n){
        int num;
        cin >> num;
        if((i+1)%2){
            maxio = max(num,maxio);
            arro.pb(num);
        }else{
            maxie = max(num,maxie);
            arre.pb(num);
        }
    }

    int anse = maxie + arre.size();
    int anso = maxio + arro.size();
    int ans = max(anse,anso);

    
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}