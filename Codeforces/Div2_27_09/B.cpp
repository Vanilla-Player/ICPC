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
map<ll,ll>sols;
void solve(){

    ll n,q;
    cin >> n >>q;
    vector<ll>arr(n+1);
    vector<ll>querys(q);
    fora(i,1,n){
        cin >> arr[i];
    }
    sols.clear();

    fora(i,1,n-1){
        sols[1LL*(i*(n-i))]+=arr[i + 1] - arr[i] - 1; // got n = 3 => i = 1, i(n-i)= 2. i = 2, i(n-i) = 2
        
    }
    fora(i,1,n)sols[1LL*(i-1)*(n-i)+n-1]++; // i = 1, (i-1)*(n-i)+n-1 = 2;  i = 2, (i-1)*(n-i)+n-1 = 3
    
    fori(i,q){
        cin >> querys[i];
    }

    fori(i,q){
        ll k = querys[i];
        cout << sols[k] << " ";
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

// 4 10
// 1 2 3 4
// 1 2 3 4 5 6 7 8 9 10