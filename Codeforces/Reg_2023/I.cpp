#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef __uint128_t u128;
#define ford(i,a,n) for(int i = (a); i >= (n); i++)

#define pb push_back
#define mp make_pair

#define ull unsigned long long

#define dprint(v) cout << #v"=" << v << endl //;)

#define fora(i,a,n) for(ull i = (a); i <= (n); i++)
#define fori(i,n) for(ull i = 0; i < (n); i++)

const ull INF = 1000000007;
const ull MOD = 1e9 + 7;
const ull MAXN = 100004;


ull n;

ull solve(string &word, u128 n){

    vector<ull>appe(26,0);
    for (auto c: word)
    {
        appe[c-'a']++;
    }

    u128 ans = 0;
    vector<ull>counted_before(26);
    for(auto c:word){
        u128 bef = 0;
        u128 aft = 0;
        fora(l, (c-'a') +1,25){
            aft = (aft + appe[l])%MOD;
            bef = (bef + counted_before[l])%MOD; // count from behind to front
        }
        ans = (ans + bef*n + aft *(((n-1)*n/2)%MOD))%MOD; // calculate for each caracter all the occ, and accum
        counted_before[c-'a']++;
    }

    return ans;
    
}


int main(){

    ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

    
    string word;
    cin >> word >> n;

    auto ans = solve(word,n);
    
    cout << ans;
    cout << "\n";
}