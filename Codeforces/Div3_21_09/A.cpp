#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int gived = 0;
        int money = 0;
        fori(i,n){
            int num;
            cin >> num;
            if(num == 0 && money > 0){
                gived++;
                money--;
            }
            if(num >= k){
                money+=num;
                
            }
        }

        cout << gived << "\n";
    }


    // Para que ande mass rapido
}