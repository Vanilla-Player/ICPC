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
vector<ll> P;
vector<ll>C;
ll n;


bool can(ll contests){

    ll acumulado = 0;
    forn(i,n){
        acumulado += P[i];

        if(acumulado < contests*C[i]){
            return false;
        }

        acumulado -= contests*C[i];
    }

    return true;
}

int main() {
// freopen("input.in", "r", stdin);
// ios::sync_with_stdio(0);

    cin >> n;
    forn(i,n){
        ll ci;
        cin >> ci;
        C.pb(ci);
    }

    forn(i,n){
        ll pi;
        cin >> pi;
        P.pb(pi);
    }

    ll l = 0;
    ll r = 1e9 + 5;

    while(l + 1<r){
        ll mid = (l+r)/2;

        if(can(mid)){
            l = mid; 
        }else{
            r = mid;
        }
    }

    cout << l << endl;

    return 0;
}