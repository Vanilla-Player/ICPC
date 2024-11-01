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
    string s;
    cin >> s; 
    fora(i,1,n){
        if(n%i == 0){

            int rep = 2;
            fori(j,i){ // to the string 
                for (int k = j+i; k < n;k+=i) // jumps of length i
                {
                   if(s[k]!=s[j]){
                    rep--;
                   }
                }
                
            }
            if(rep > 0){
                cout << i << "\n";
                return;
            }
            rep = 2;
            for (int j = n - i; j < n;j++){ // to the string 
                for (int k = j-i; k >=0;k-=i) // jumps of length i
                {
                   if(s[k]!=s[j]){
                    rep--;
                   }
                }
                
            }
            if(rep > 0){
                
                cout << i << "\n";
                return;
            }
        }
    }

    cout << s.size() << "\n";
    return;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}