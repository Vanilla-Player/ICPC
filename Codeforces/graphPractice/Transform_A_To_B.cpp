#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;


ll target;
vector<ll> sequence;


bool dfs(ll n){

    if(n > target){
        return false;
    }

    if(n == target ){
        sequence.pb(n);
        return true;
    }

    if(dfs(10*n + 1) || dfs(2*n)){
        sequence.pb(n);
        return true;
    }
    
    return false;
}


int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n >> target;
    if(dfs(10*n+1) || dfs(2*n)){
        sequence.pb(n);
        cout << "YES" << "\n";
        cout << sequence.size() << "\n";
        ford(i,sequence.size() - 1, 0){
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return 0;
    }
    cout << "NO" << endl;
    return 0;

}