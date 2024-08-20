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
ll n,t;


int main(){
    cin >> t;
    while(t--){

        cin >> n;

        vector<string> m(2);

        forn(i,2){
            string s;
            cin >> s;
            m[i] = s;
        }

        int ans = 0;
        forr(i,1,n-1){
            // . . .
            // x . x
            if(m[0][i] == '.' && m[0][i-1] == '.' && m[0][i+1] == '.' && m[1][i] == '.' && m[1][i-1] == 'x' && m[1][i+1] == 'x'){
                ans++;
            }else if(m[1][i] == '.' && m[1][i-1] == '.' && m[1][i+1] == '.' && m[0][i] == '.' && m[0][i-1] == 'x' && m[0][i+1] == 'x'){
                ans++;
            }
        }

        cout << ans << "\n";

    }

}



