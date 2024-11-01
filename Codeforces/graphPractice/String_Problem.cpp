#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
typedef long long ll;
typedef __uint128_t u128;
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

const int MAXN = 100050;
const ll INF = 1e9;

// ll g[27][27];
ll d[27][27];
ll cost[MAXN];
string s1, s2;
int m;

void floyd_M(){

    fori(k,26){
        fori(i,26){
            fori(j,26){
                if(j == i)continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){

    cin >> s1 >> s2;
    cin >> m;

   

    fori(i,26){
        fori(j,26){
             if(j == i){
                d[i][j] = 0;
                continue;
             }
             d[i][j] = INF;
        }
    }
    

    fori(i,m){
        char from,to;
        int w;
        cin >> from >> to >> w;
        int mini = d[from - 'a'][to - 'a'];
        d[from - 'a'][to - 'a'] = min(mini,w);
    }

     if(s1.size() != s2.size()){
        cout << -1 << endl;
        return 0;
    }

    // fori(i,26){
    //     fori(j,26){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    floyd_M();

    int n = s1.size();
    fori(i,n){
        
        char c1 = s1[i];
        char c2 = s2[i];
        if(c2 == c1)continue;
        int i1 = c1 - 'a';
        int i2 = c2 - 'a';
        int to_sum = INF;

        fori(k,26){
            if(to_sum > d[i1][k] + d[i2][k]){
                to_sum = d[i1][k] + d[i2][k];
                // cout << "CHANGE\n";
                // dprint(k);
                // dprint(i1);
                // dprint(i2);
                s1[i] = k + 'a';
            }
        }
        if(to_sum >= INF){cout << "-1\n";return 0;} 
        cost[i] += to_sum;
    }

    int sum = 0;
    fori(i,n){
        sum +=cost[i];
    }
    cout << sum << "\n";
    cout << s1 << "\n";
    return 0;

}