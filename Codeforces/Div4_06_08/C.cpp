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
typedef pair<ll,ll> llp;
const int MAXN=100100;


bool comp(const llp &a ,const llp &b){
    return a.fst < b.fst;
}

int main(){

//     3 3 10
// 1 2
// 3 5
// 6 8


 ll t;
 cin >> t;
 while(t--){

    ll n,s,m;

    cin >> n >> s >> m;

    vector<llp> tasks;
    forn(i,n){
        ll l,r;
        cin >> l >> r;
        tasks.pb(make_pair(l,r));
    }

    sort(tasks.begin(),tasks.end());

    bool flag = false;

    if(tasks[0].fst >= s){
        
        cout << "YES" << endl;
        // cout << "flagged1" << endl;
        continue;
    }
    ll end = tasks[0].snd;
    forr(i,1,n){
        llp task = tasks[i];
        if(task.fst - end >= s){
            flag = true;
            break;
            // cout << "flagged2" << endl;
        }
        end = task.snd;
    }
    if(!flag && m - end >= s){
        flag = true;
        // cout << "flagged3" << endl;
    }

    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
     }

 }   

}