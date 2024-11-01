#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable

typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;



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

    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    
    char maxi = 'a';
    fori(i,n){
        if(s[i] > maxi){
            if(s[i] - 'a' > k){
                k -= maxi - 'a';
                int to = s[i] - k;
                for (char c = s[i]; c > to; c--)
                {
                    for(char &e:s){
                        if(e == c){
                            e = char(e-1);
                        }
                    }
                }
                break;
            }else{
                maxi = max(s[i],maxi);
            }
        }
    }

    for(char &e: s){
        if(e <= maxi){
            e = 'a';
        }
    }
    cout << s << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}