#include <bits/stdc++.h>
using namespace std;
#define  dprint(v) cout << #v"=" << v << endl //;)
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
typedef long double ld;
typedef pair<int,int> ii;
const int MAXN=100100;

int main(){


 int c;
 cin >> c;
 while(c--){

    int a1,a2,b1,b2;

    cin >> a1 >> a2 >> b1 >> b2;

    int ans = 0;
    if(a1 > b1 && a2 > b2){
        ans++;
    }
    if(a1 == b1 && a2 > b2){
        ans++;
    }
    if(a1 > b1 && a2 == b2){
        ans++;
    }
    if(a2 > b1 && a1 > b2){
        ans ++;
    }
    if(a2 == b1 && a1 > b2){
        ans ++;
    }
    if(a2 > b1 && a1 == b2){
        ans ++;
    }
    if(a2 > b2 && a1 > b1){
        ans++;
    }
    if(a2 == b2 && a1 > b1){
        ans++;
    }
    if(a2 > b2 && a1 == b1){
        ans++;
    }
    if(a1 > b2 && a2 > b1){
        ans++;
    }
    if(a1 == b2 && a2 > b1){
        ans++;
    }
    if(a1 > b2 && a2 == b1){
        ans++;
    }

    cout << ans << endl;;
 }   

}