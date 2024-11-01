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
        int n0,n1,n2;
        cin >> n0 >> n1 >> n2;

        if(n1 == 0){
            if(n0 != 0){
                cout << string(n0+1,'0') << "\n";
                continue;
            }else{
                cout << string(n2+1,'1') << "\n";
                continue;
            }
        }

        string ans = "";
        fora(i,0,n1){
            if(i%2){
                ans+="0";
            }else{
                ans+="1";
            }
        }
        
        ans.insert(1,string(n0,'0'));
        ans.insert(0,string(n2,'1'));
        cout << ans << "\n";

    }
}