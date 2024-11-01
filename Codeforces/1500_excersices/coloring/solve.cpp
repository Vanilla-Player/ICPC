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
        ll n,m,k;
        cin >> n >> m >> k;
        int a[m];
        fori(i,m){
            cin >> a[i];
        }
        ll fl =0;
        ll nk = (n)/k;
        nk += (n % k)?1:0;
        fori(i,m){
            ll ai = a[i];
            
            if(ai > nk){
                // paint ai
                fl=1<<30;    
            }else if(ai == nk){
                // paint 
                fl++;
            }

        }
        // dprint(ans);
        if(fl <= (n-1)%k + 1){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }

}