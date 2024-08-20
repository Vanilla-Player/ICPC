#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;
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


int main() {

cin >> t;
    while(t--){

        cin >> n;
        int counter = 0;
        // dprint(n/4);
        while(n/2 != 0 || n/4 != 0){
            if(n/4){
                counter+=(n/4);
                n-=4*(n/4);
            }else if(n/2){
                counter+=(n/2);
                n-=2*(n/2);
            }
        }
        cout << counter << endl;
    }

return 0;
}


