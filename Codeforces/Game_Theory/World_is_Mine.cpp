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
 
int t;
int F[5001];
int dp[5001][5001];
 
void solve(){
 
    map<int,int> cnt;
    int n;
    cin >> n;
 
    fori(i,n){
        int x;
        cin >> x;
        cnt[x]++;
    }
 
    
    int K = 1;
    for(auto [k, v]: cnt){
       F[K] = v;
        K++;
        
    }
    K--;
 
    dprint(K);
    
    for (int s = 1; s <= K; s++) dp[1][s] = -INF;
 
    dp[0][0] = 0;
    dp[1][0] = 0;
 
    fora(i,2,K){    
        fora(k,0,i){
            // dprint(k);
            dp[i][k] = dp[i-1][k];
            if( k - F[i] - 1 >= 0){
                dp[i][k] = max(dp[i][k],dp[i - 1][k - F[i] - 1]+1);
            }
            
        }
    }
 
    fori(i,K+1){
        fori(j,K+1 ){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
      
    int ans = max(dp[0][0],0);
    fora(i,0,K+1){
        ans = max(dp[K][i],ans);
    }
    //  cout << "ANS" << "\n";
    cout << K - ans << "\n";
 
}
 
int main(){
    cin >> t;
    while(t--){
        solve();
    }
}