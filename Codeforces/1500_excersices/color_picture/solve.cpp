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

    ll n,m,k;
    cin >> n >> m >> k;
    ll sum = 0;
    vector<ll>a(k);
    bool pinto_todo = false;
    fori(i,k){
        cin >> a[i];
    }

    bool b;
    ll tot = 0;
    b = false;
    tot = 0;
    fori(i,k){

        if(a[i]/n > 2){
            b=true;
        }
        if(a[i]/n>=2){
            tot+=a[i]/n;
        }
    }

    if(tot >= m && (b || m%2==0)){
        cout << "Yes\n";
        return;
    }


    b = false;
    tot = 0;
    fori(i,k){

        if(a[i]/m > 2){
            b=true;
        }
        if(a[i]/m>=2){
            tot+=a[i]/m;
        }
    }

    if(tot >= n && (b || n%2==0)){
        cout << "Yes\n";
        return;
    }

    cout << "No\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    

}
