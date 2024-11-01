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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll maxi = 0;
        ll k = 0;
        bool allNeg = true;
        ll a[n];
        ll maxNeg = -1e9;
        fori(i,n){
            ll p;
            cin >> a[i];
            if(a[i]>0){
                allNeg = false;
            }
            
            maxNeg = max(maxNeg,a[i]);
        }
        if(allNeg){
            cout << maxNeg << "\n";
            continue;
        }
        ll a1 = 0;
        ll a2 = 0;
        fori(i,n){
            if(i%2){
                ll c1 = a[i];
                ll zero = 0;
                a1 += max(zero,c1);
            }else{
                ll c1 = a[i];
                ll zero = 0;
                a2 += max(zero,c1);
            }
        }
        cout << max(a1,a2) << "\n";
    }
}