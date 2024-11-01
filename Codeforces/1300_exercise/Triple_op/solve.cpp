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


int search_range(int l, int r, int p){
    // cout << "BINARY\n";
    // dprint(l);
    // dprint(r);

    while(l<=r){
        int mid = (l+r)/2;
        // cout << "Result: " << (int)(mid/pow(3,p)) << "\n";
        if((int)(mid/pow(3,p)) > 0){
            // cout << "Reduce\n";
            r = mid - 1;
        }else{
            // cout << "Increase\n";
            l = mid + 1;
        }
    }

    return r;

}

void solve(){

    int l,r;
    cin >> l >> r;
    int l0 = 1;

    while((int)(l/pow(3,l0)) > 0){
        // cout << pow(3,l0) << "\n";
        // cout << l/pow(3,l0) << "\n";
        l0++;
    }
    // dprint(l0);

    int ans = l0;
    int p = l0;
    int n = 0;
    fora(i,l,r){
        // cout << "IT: " << i << "\n";
        if((int)(i/pow(3,p)) > 0){
            // cout << (int)(i/pow(3,p)) << "\n";
            p++;
        }
        // busco el ultimo valor que entra en la potencia
        // dprint(p);
        n = search_range( i,  r,  p);
        // dprint(n);
        // dprint((n-(i-1))*p);
        ans += (n-(i-1))*p;

        i+=(n-i);
    }
    // cout << "ANS\n";
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}