#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
const int MAXN=100100;
ll n,q,k,t;


int main() {
// freopen("input.in", "r", stdin);
// ios::sync_with_stdio(0);
cin >> t;
while(t--){

    cin >> n >> k >> q;

    ll cont = 0;
    vector<ll> temperatures(n);

    forn(i,n){
        ll temp;
        cin >> temp;
        temperatures[i] = temp;
    }

    ll streak = 0;
    ll total = 0;

    forn(i,n){
        if(temperatures[i] <= q){
            streak++;
            total += max(0ll,streak - k + 1);
            }else{
                streak = 0;
            }
        

    }

    
    cout << total << endl;


}
return 0;
}

