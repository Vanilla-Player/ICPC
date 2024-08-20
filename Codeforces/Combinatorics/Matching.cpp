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
ll n,t;
string s;


int main() {
// freopen("input.in", "r", stdin);
// ios::sync_with_stdio(0);
    cin >> t;
    while(t--){

        cin >> s;
        ll ans = 1;
        bool bandera = false;

        forn(i,s.size()){
            if(i==0 && s[i] == '0'){
                cout << "0" << endl;
                bandera = true;
                break;
            }else if(i==0 && s[i] == '?'){
                ans*=1LL*9;
            }else if(s[i] == '?'){
                ans*=1LL*10;
            }
        }

        if(!bandera){

            cout << ans << endl;
        }

    }

return 0;
}


