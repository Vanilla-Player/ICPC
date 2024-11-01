#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define fori(i,n) for(int i = 0; i < (n);i++)
#define fora(i,a,n) for(int i = (a); i <= (n);i++)
#define ford(i,n) for(int i = (n); i >= 0;i--)

#define fill(a, v) memset(a, (long long)v, sizeof(a))
#define oper max
#define int long long
const int INF = 1e9 + 7;
const int MAXN = 200005;

// Para printear Variables
#define  dprint(v) cout << #v"=" << v << endl //;) 
// Si lleva ")" al final


int t,n,x;

void solve(){

    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];


        partial_sum(a.begin() + 1, a.end(), a.begin() + 1);


    fori(i,a.size()-1){
        cout << a[i] << " ";
    }
    cout << "\n";
    vector<int> dp(n+2);

for (int i = n - 1; i >= 0; --i) {
            int q = upper_bound(a.begin(), a.end(), a[i] + x) - a.begin();
            dp[i] = dp[q] + q - i - 1;
        }

    
        cout << accumulate(dp.begin(), dp.end(), 0ll) << '\n';

}


signed main(){
    cin >> t;
    while(t--){
        solve();
    }

}
