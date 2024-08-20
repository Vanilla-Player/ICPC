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
const int MAXN=2005;
ll a,b,c,t;
// 3 
// 1 1 1
// 1 1 1
// 1 1 1 


int main() {
// freopen("input.in", "r", stdin);
// ios::sync_with_stdio(0);
 cin >> t;
 while(t--){

    cin >> a >> b >> c;
    ll total = a + b + c;
    if(total%9 != 0){
        cout << "NO" << endl;
        continue;
    }

    ll rounds = (a+b+c) / 9;
    if(min({a,b,c}) >= rounds){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
 }
    // ll x = (a+b+c)% 6 ;
    // cout << x << endl;


return 0;
}

