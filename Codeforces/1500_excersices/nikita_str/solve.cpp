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
    string s;
    cin >> s;
    int n = s.size();
    vector<int>prefa(n + 1);
    vector<int>prefb(n + 1);
    fori(i,n){
        char c = s[i];
        if(c == 'a'){
            prefa[i+1] = prefa[i] + 1;
            prefb[i+1] = prefb[i];
        }else{
            prefb[i+1] = prefb[i] + 1;
            prefa[i+1] = prefa[i];
        }
    }

    int max_len = 0;
    fora(i,0,n){
        fora(j,i,n){ 
            int len = prefa[n] - prefa[j] + prefb[j] - prefb[i] + prefa[i]; 
            max_len = max(len,max_len);
        }
    }
    cout << max_len << "\n";

}