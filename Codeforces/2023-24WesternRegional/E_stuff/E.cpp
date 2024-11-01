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

int main(){
    int n,q;
    cin >> n >> q;
    vector<int>potencias(n+1,0);

    while(q--){
        char id;
        cin >> id;
        if(id == '!'){
            // update
            int a,b;
            cin >> a >> b;
            potencias[a]+=potencias[b]+1;
            // dprint(q);
            // dprint(potencias[a]);
            // dprint(potencias[b]);
            // dprint(a);
            // dprint(b);
            // assert(potencias[a] > potencias[b]);
        }else{
            // queries
            int a, b;
            cin >> a >> b;

            if(potencias[a] > potencias[b]){
                cout << ">\n";
            }else if(potencias[a] < potencias[b]){
                cout << "<\n";
            }else{
                cout << "=\n";
            }
        }
    }
    
}