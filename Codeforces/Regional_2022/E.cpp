#include <bits/stdc++.h>
 
 
using namespace std;
 
 
#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define ll long long
 
// Para printear Variables
#define  dprint(v) cout << #v"=" << v << endl //;) 
// Si lleva ")" al final
 
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1010;

vector<vector<ll> >dp(MAXN, vector<ll>(MAXN,-1));


string s; ll n;

ll has_sol(ll x, ll acum){
    if(x == s.size() && acum == 0) return 1;
    if(x == s.size()) return 0;


    if(dp[x][acum] != -1)return dp[x][acum];

    if(s[x] == '?'){
        dp[x][acum] = 0;
        ll start = 0;
        if(x == 0){
            start++;
        }
        // dprint(start);
        // return -1;
        fora(i,start, 9){
            dp[x][acum] = max(dp[x][acum], has_sol(x+1, (acum*10+i)%n));
        }
    }else{
        ll d = s[x] - '0';
        dp[x][acum] = has_sol(x+1,(acum*10+d)%n);
    }

    return dp[x][acum];

}

string ans;

void build(ll x, ll acum){
    if(x == s.size()) return;

    if(s[x] == '?'){

        ll start = 0;
        if(x == 0){
            start++;
        }

        fora(i,start,9){
            if(has_sol(x+1, (acum*10+i)%n)){
                ans.pb(i+'0'); // Sumo para que el ascii sea el correcto
                build(x+1, (acum*10+i)%n);
                return;
            }
        }
    }else{
        ans.pb(s[x]);
        build(x+1, (acum*10+s[x]-'0')%n);
        return;
    }
}


int main(){

    cin >> s >> n;

    if(!has_sol(0,0)){
        cout << "*" << "\n";
        return 0;
    }

    build(0,0);

    cout << ans << endl;
    
}