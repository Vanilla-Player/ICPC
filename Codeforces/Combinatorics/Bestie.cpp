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
int gcd(int a, int b) {
 if (b == 0) return a;
 return gcd(b, a%b);
}

int main() {
// freopen("input.in", "r", stdin);
// ios::sync_with_stdio(0);
cin >> t;
while(t--){

    cin >> n;
    ll g = 0;
    vector<ll>nums(n);
    forn(i,n){
        ll num;
        cin >> num;
        nums[i]= num;
        g = gcd(nums[i],g);
    }

    if(g == 1){
        cout << "0\n";
        continue;
    }

    if(gcd(g,n) == 1){
        cout << "1\n";
        continue;
    }
    
    if(gcd(g,n - 1) == 1){
        cout << "2\n";
        continue;
    }
    
    cout << "3\n";


}
return 0;
}