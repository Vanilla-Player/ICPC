#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
typedef __uint128_t u128;
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

#define EPS 1e-9


int main(){

    int n;
    cin >> n;
    vector<int>figures;
    fori(i,n){
        int figure;
        cin >> figure;
        figures.pb(figure);
    }
    int sum = 0;
    int lst = 1;
    fori(i,n){
        int x = figures[i];
        
        if(x != 1 && lst!= 1){
            cout << "Infinite\n";
            return 0;
        } 
        if(x != 1){
            sum += x+1;
            if(i != 0 && i != n-1){
                sum+= x+1; // sum becuase next would be circle
            }
        }
        lst = x;
    }

    fori(i,n-2){
        if(figures[i] == 3 && figures[i + 2] == 2)sum--;
    }

    cout << "Finite\n";
    cout << sum << "\n";
    return 0;

}