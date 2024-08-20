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


int main(){

    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;


        if(s[0] == '1' && s[1] == '0' && ((s[2] - '0' >= 2)||((s.size()> 3)&&(s[2]- '0' >= 1)))){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;

}