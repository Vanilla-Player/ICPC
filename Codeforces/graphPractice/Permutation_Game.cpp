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
const int MAXN = 200005;


ll t, n, s1,s2;




ll play(vector<ll>&p, vector<ll>&a, ll s , ll k){
    int n = p.size();
    ll mx = 0;
    ll acum = 0;
    vector<bool>visited(n);
    while(!visited[s] && k > 0){
        visited[s] = 1;
        mx = max(mx, acum + 1LL*k*a[s]);
        acum += a[s];
        s = p[s];
        k--;
    }
    return mx;

}

void solve(){
    ll k;
    cin >> n >> k >> s1 >> s2;
    vector<ll>p(n);
    vector<ll>a(n);

    fori(i,n){
        cin >> p[i];
        p[i]--;
    }

    fori(i,n){
        cin >> a[i];
    
    }

    ll B = play(p,a,s1 - 1,k);
    ll S = play(p,a,s2 - 1,k);

    if(B == S){
        cout << "Draw" << "\n";
        
    }else if(B > S){
        cout << "Bodya" << "\n";
    }
    else{
        cout << "Sasha" << "\n";    
        
    }
    
}


int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t;
    
    while(t--){
        solve();
    }

    return 0;

}