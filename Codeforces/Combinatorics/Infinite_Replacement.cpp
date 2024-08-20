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
string s1,s2;


int main() {
// freopen("input.in", "r", stdin);
// ios::sync_with_stdio(0);
    cin >> t;
    while(t--){

        cin >> s1;
        cin >> s2;

        if(s2 == "a"){
            cout << 1 << endl;
            continue;
        }
        ll count_a = 0;
        bool infinite = false;
        forn(i,s2.size()){
            if(s2[i] == 'a'){
                cout << -1 << endl;
                infinite = true;
                break;
            }
        }
        if(infinite){
            continue;
        }

        ll res = 1;

        forn(i,s1.size()){
            res *=2*1LL;
        }
        

        cout << res << endl;

    }

return 0;
}


