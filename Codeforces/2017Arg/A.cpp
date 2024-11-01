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


const int INF = 1000000007;
const int MOD = 1000000007;
const int MAX = 100000004;

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll n;
    cin >> n;
    vector<ll>piratas(n);
    vector<ll>cofres(n);

    fori(i,n){
        cin >> piratas[i];
    }

    fori(i,n){
        cin >> cofres[i];
    }

    sort(cofres.rbegin(), cofres.rend());
    sort(piratas.rbegin(), piratas.rend());

    ll pick = 0;
    ll ans = 1;
    fori(p,n){
        while(pick < n && cofres[pick] >= piratas[p]){
            pick++;
        }
        ll cofres_elegidos = pick - p;
        ans*= cofres_elegidos;
        ans%=MOD;
    }

    cout << ans%MOD << endl;
    return 0;


}

// TEST

// 2
// 2 2 
// 1 1000000000

// 3
// 2 1 3
// 3 2 4

// 13 
// 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1