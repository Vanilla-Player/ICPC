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
vector<vector<int>> matriz;

int main() {

cin >> t;
    while(t--){

        cin >> n >> k;

        vector<string> matriz;
        // dprint(n/4);
        forn(i,n){
            string s;
            cin >> s;
            matriz.pb(s);
        }

        for (int i = 0; i < n;)
        {
            
            for (int j = k - 1; j < n;)
            {
                cout << matriz[i][j];

                j+=k;
            }
            cout << endl;
            i+=k;
        }
        

    }

return 0;
}


