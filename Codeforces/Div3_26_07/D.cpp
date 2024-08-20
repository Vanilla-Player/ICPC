#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;
#define forr(i,a,b) for(ll i=(a); i<(b); i++)
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
ll n,x,t;


int main() {

cin >> t;
    while(t--){

            cin >> n >> x;
            ll ans = 0;
            
            forr(a,1,n){
                ll b = 1;
                while( x-(a+b) > 0 && (n-1LL*(a*b))/(a+b) > 0){
                    // dprint(x-1LL*(a+b));
                    // dprint((n-1LL*(a*b)));
                    // dprint(a+b);
                    ans += min(x-1LL*(a+b),(n-1LL*(a*b))/(a+b));
                    b++;
                }
            }
        cout << ans << endl;
    }

return 0;
}


