#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define fori(i,n) for(int i = 0; i < (n); i++)
#define fora(i,a,n) for(int i = (a); i <= (n); i++)
#define ford(i,a,n) for(int i = (a); i >= (n); i++)

#define pb push_back
#define mp make_pair

#define dprint(v) cout << #v"=" << v << endl //;)

void solve(){

    map<ll,ll>freq;
    ll n, k;
    cin >> n >> k;
    fori(i,n){
        ll num;
        cin >> num;
        freq[num]++;
    }

    ll l = 0;
    ll r = 0;
    ll sum = 0;
    ll ans = 0;
    for(auto p :freq){
        ll now = p.first;
        // cout << "GO\n";
        // dprint(l);
        // dprint(r);

        // termina la ventana
        if(now != r + 1){
            sum = freq[now];
            r = now;
            ans = max(ans,sum);
            l = now;
            continue;
        }

        // ventana es k
        if(r - (l - 1) >= k){
            // cout << "Llego a K\n";
            sum -= freq[l];
            l++;
        }

        sum += freq[now];
        r = now; // sabemos que now es r + 1
        ans = max(ans,sum);
    }
    cout << ans <<"\n";


}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}