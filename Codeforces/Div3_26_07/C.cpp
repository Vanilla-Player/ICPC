#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;
#define forr(i,a,b) for(ll i=(a); i<(b); i++)
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
ll n,x,t,q;



int main() {

cin >> t;
    while(t--){

        cin >> n >> q;
        vector<vector<int> > pre1(n+1,vector<int>(26));
        vector<vector<int> > pre2(n+1,vector<int>(26));

        forr(i,1,n + 1){
            char c;
            cin >> c;
            pre1[i][c - 'a'] ++;

            forn(j,26){
                pre1[i][j] += pre1[i - 1][j]; 
            }
        }
    

        forr(i,1,n + 1){
            char c;
            cin >> c;
            pre2[i][c - 'a'] ++;

            forn(j,26){
                pre2[i][j] += pre2[i - 1][j]; 
            }
        }

        forn(i,q){
            ll l,r, ans=0   ;
            cin >> l >> r;
 
            forn(c,26){
                ll dif1 = pre1[r][c] - pre1[l-1][c];
                ll dif2 = pre2[r][c] - pre2[l-1][c];

                ans+= abs(dif1 - dif2);
            }
            // ans /= 2;

            cout << ans / 2 << endl;

        }
    
    }

return 0;
}

