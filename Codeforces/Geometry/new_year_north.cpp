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



int main(){
    int n;
    cin >> n;
    int cur = 0;
    bool good = true;
    fori(i,n){
        string dir; 
        int steps;
        cin >> steps >> dir;
        // cout << dir << "\n";
        // stay at north
        if(cur == 0 && dir[0] != 'S'){
            good = false;
        }
        // stay at south
        if(cur == 20000 && dir[0] != 'N'){
            good = false;
        }


        if(dir[0] == 'S'){
            if(cur + steps > 20000){
                good = false;
            }
            cur+=steps;
        }

        if(dir[0] == 'N'){
            if(cur - steps < 0){
                good = false;
            }
            cur-= steps;
        }

    }
    if(!good){
        cout << "NO\n";
        return 0;
    }

    if(cur == 0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}