// https://codeforces.com/problemset/problem/1791/F

#include <bits/stdc++.h>

using namespace std;

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

const int MAXN = 200005;

void solve(){

    int n;
    cin >> n;
    vector<int>arr(n+1);
    vector<int>dp(n+1, MAXN);
    fori(i,n){
        cin >> arr[i];
    }
    arr[n] = 0;

dp[0] = 0;
    fora(i,0,n){// i <= n

        if(i != 0){
            dp[i] = min(dp[i - 1] + 1, dp[i]);
        }

        if((arr[i] + i + 1) <= n){
            // dprint(i);
            assert(i != n);
            // dprint(arr[i]+ i + 1);
            dp[arr[i]+ i + 1] = min(dp[arr[i]+ i + 1], dp[i]);
            // dprint(dp[n]);
        }

        
    }
    cout << dp[n] << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}