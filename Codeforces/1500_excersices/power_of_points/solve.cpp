#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable

typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;


#define ll long long

// Metodos para vectores, sets y maps
#define each(it, s) for (vit it = s.begin(); it != s.end(); ++it)
#define sortAsc(v) sort(v.begin(), v.end())
#define sortDesc(v) sort(v.begin(), v.end(), greater<auto>())
#define fill(a, v) memset(a, v, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

// Iterar
#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

#define fi first
#define se second
#define mp make_pair
#define pb push_back

// Para printear Variables
#define  dprint(v) cout << #v"=" << v << endl //;) 
// Si lleva ")" al final


void solve(){

    int n;
    cin >> n;
    ll a[n+1];
    pair<int,int> x[n+1];
    ll s1 = 0,s2 = 0;
    fora(i,1,n){
        cin >> x[i].fi;
        x[i].se = i;
        s2+=x[i].fi;
    }

    sort(x+1,x+n+1);

    fora(i,1,n){
        s1+=x[i].fi;
        s2-=x[i].fi;
        a[x[i].se] = n + 1ll*x[i].fi*(2*i-n)-s1+s2;
    }

    fora(i,1,n){
        cout << a[i] << " ";
    }
    cout << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}