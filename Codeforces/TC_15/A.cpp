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
ll a,b,c,x,y, t;
string s;


int main() {
// freopen("input.in", "r", stdin);
// ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> x >> y;

        bool cat = false;
        bool dog = false;

        if(a >= x){
            dog = true;
        }else if(a + c >= x){
            dog = true;
            c -= x - a;
        }

        if(b >= y){
            cat = true;
        }else if(b + c >= y){
            cat = true;
            c -=  y - b;
        }
        

        if(cat && dog){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }

return 0;
}


