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
typedef pair<int,int> ii;
const int MAXN=100100;
ll n,k,t;



int main(){

    cin >> n >> k;

    string s;

    vector<int>sequence;
    vector<int>pressed;

    forn(i,n){
        int v;
        cin >> v;
        sequence.pb(v);
    }

    cin >> s;
    
    ll ans = 0;
    ll p = 0;
    char b = ' ';
    forn(i,n){
        // dprint(i);
        // dprint(s[i]);
        // dprint(b);
        if(s[i] != b && i != 0){
            // calculate max on k pressed buttons
            sort(pressed.rbegin(),pressed.rend());
            int count = 0;
            forn(j,p){
                if (count == k)break;
                // dprint(pressed[j]);
                ans += pressed[j];
                count++;
            }
            //Restart counters
            p = 1;
            b = s[i];
            pressed.clear();
            pressed.pb(sequence[i]);
            // dprint(pressed.size());
        }else{
            p++;
            b = s[i];
            pressed.pb(sequence[i]);
        }

        if(i == n-1){
            sort(pressed.rbegin(),pressed.rend());
            int count = 0;
            forn(j,p){
                if (count == k)break;
                // dprint(pressed[j]);
                ans += pressed[j];
                count++;
            }
        }

    }


    cout << ans << endl;

    return 0;

}