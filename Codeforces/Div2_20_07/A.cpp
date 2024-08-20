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
// freopen("input.in", "r", stdin);
// ios::sync_with_stdio(0);
cin >> t;
    while(t--){
        cin >> n;
        multiset<int> nums;
        int maximo  = 0;
        forn(i,n){
            int num;
            cin >> num;
            nums.insert(num);
            // dprint(num);
            if(num > maximo){
                maximo = num;
            }
        }   

        bool even = true;
        forr(i,1,n){
            if(nums.count(i) % 2 == 1){
                even = false;
                break;
            }
        }

        int appears = nums.count(maximo);
        // dprint(nums.size()); 
        if(appears % 2 == 0 && nums.size() % 2 == 0 && even){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }

    }


return 0;
}


