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



int main(){
    int p = 0;
    int m = 0;
    int n;
    cin >> n;
    fora(i,1,n){
        char c;
        cin >> c;
        if(c == '+'){
            p++;
            continue;
        }
        m++;
        continue;
    }

    ll tot = p - m;
    int q;
    cin >> q;
    while(q--){
        ll x,y;
        cin >> x >> y;
        if(tot == 0){
            cout << "YES\n";
            continue;
        }

        ll toty = tot*y;
        ll delta = y-x;

        if(delta == 0){
            cout << "NO\n";
            continue;
        }

        if(toty % delta){
            cout << "NO\n";
            continue;
        }

        ll i = toty /delta;        
        
        cout << ((i >= -m && i <= p)?"YES\n" : "NO\n");
    }


}

