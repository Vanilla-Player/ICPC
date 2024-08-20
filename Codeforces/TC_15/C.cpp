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
ll n,m;
string s;
vector<vector<char> >matrix(MAXN,vector<char>(MAXN));


int main() {
// freopen("input.in", "r", stdin);
// ios::sync_with_stdio(0);
    cin >> n >> m;
    forr(i,1,n+1){
        forr(j,1,m+1){
            char c;
            cin >> c;
            matrix[i][j] = c;
        }
    }

        forr(i,1,n+1){
            forr(j,1,m+1){
            char c;
            cout << matrix[i][j] << " ";
            
        }
        cout << endl;
        }

return 0;
}


