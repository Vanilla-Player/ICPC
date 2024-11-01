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



vector<ll>a;
ll n,q;
ll tot = 0;


void solve(){

    cin >> n;
    a = vector<ll>(n);
    fori(i,n){
        cin >> a[i];
        tot += a[i];
    }
    cin >> q;
    sort(a.begin(),a.end());

    fori(qq,q){
        ll x, y;
        cin >> x >> y;

        int i = lower_bound(a.begin(), a.end(), x) - a.begin();
        ll ans = 2e18;

        if(i > 0){ // i = 0 => Todos son mayor que x. Por lo que solo necesito darle a y(maybe) para y
            ans = min(ans, (x - a[i - 1]) + max(0LL, y - tot + a[i-1]));
        }
        if(i < n){ // i = n  => ninguno es mayor. Por lo que le tengo que dar a x y a y(maybe)
            ans = min(ans, max(0LL, y - tot + a[i]));
        }

        cout << ans << "\n";


    }

}

int main(){
    solve();

}