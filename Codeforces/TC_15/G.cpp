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
ll n;
// 3 
// 1 1 1
// 1 1 1
// 1 1 1 


ll calcular(ll num)
{
    ll x;
    if(num==0)return 1;
    if(num<10)return num;
    
    x=max(num%10 * calcular(num/10) , 9 *calcular(num/10 -1) );
    return x;
}


int main() {
// freopen("input.in", "r", stdin);
// ios::sync_with_stdio(0);


    // cin >> n;

//    cout << calcular(n) << endl;
   cout << 38%10 << endl;
 

return 0;
}

