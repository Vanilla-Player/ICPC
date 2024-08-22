#include <bits/stdc++.h>

using namespace std;

template<typename... T>
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}

#define ll long long 
#define lu long unsigned int

const ll MOD = 1000000007;
const long long inf = 1LL<<62;
const ll MAX_N = 1000005;

ll trie[MAX_N][26];
ll dp[5005];
ll end_of_word[MAX_N];

string word;
ll size_str = 0;
ll cont = 0;
void init(string x, ll x_size){
    ll node = 0;
    for (ll i = 0; i < x_size; i++)
    {
        if(!trie[node][x[i] - 'a']){
            trie[node][x[i] - 'a'] = ++cont;
            // cont++; 
        }
        node = trie[node][x[i] - 'a'];
    }
    end_of_word[node] = 1;    

}


ll search(ll x){
    ll node = 0;
    ll ans = 0;

    for (ll i = x; i < size_str; i++)
    {
        if(!trie[node][word[i] - 'a']) return ans;
        node = trie[node][word[i] - 'a'];
        if(end_of_word[node]){
            // dp[i + 1] %= MOD;
            (ans += dp[i + 1])%=MOD;
        }
    }
    return ans;
}


signed main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll k;
    cin >> word >> k;
    size_str = word.size();

    for (ll i = 0; i < k; i++)
    {
        string x;
        cin >> x;
        ll x_size = x.size();
        init(x,x_size);  
    }

    dp[size_str] = 1;
    for (ll i = size_str - 1; i >= 0; i--)
    {
        dp[i] = search(i);
    }

    cout << dp[0] << endl;

    // for (ll i = 0; i <= word.size(); i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
}