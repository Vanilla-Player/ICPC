    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef pair<int, int> ii;
    typedef vector<int> vi;
    typedef vector<ll> vl;
    typedef vector<ii> vp;
    typedef vector<long long int> vll;
    typedef vector<char> vc;
    typedef long double ld;

    typedef set<int>::iterator sit;
    typedef map<int, int>::iterator mit;
    typedef vector<int>::iterator vit;
    typedef vector<long long int>::iterator vllit;

    const int INF = 1e9 + 7;
    const int MOD = 1e9 + 7;
    const int MAXN = 1e6 + 3;

    #define _ % MOD
    #define __ %= MOD

    #define each(it, s) for (vit it = s.begin(); it != s.end(); ++it)
    #define sortAsc(v) sort(v.begin(), v.end())
    #define sortDesc(v) sort(v.begin(), v.end(), greater<auto>())
    #define fill(a, v) memset(a, v, sizeof(a))

    #define fori(i, n) for (int i = 0; i < (n); ++i)
    #define fora(i, a, n) for (int i = a; i <= (n); ++i)
    #define ford(i, a, n) for (int i = a; i >= (n); --i)
    #define pq(x) priority_queue<x, std::vector<x>, compare>

    #define min3(a, b, c) min(a, min(b, c))
    #define max3(a, b, c) max(a, max(b, c))
    #define min4(a, b, c, d) min(a, min(b, min(c, d)))
    #define max4(a, b, c, d) max(a, max(b, max(c, d)))

    #define all(a) (a).begin(), (a).end()
    #define rall(a) (a).rbegin(), (a).rend()

    #define fi first
    #define se second
    #define mp make_pair
    #define pb push_back

    #define fbo find_by_order
    #define ook order_of_key



// vl sum(200005,0); // typedef vector<ll> vl;
vector<vector<ll> > sum(1001,vector<ll>(1001));

ll query(ll y1, ll x1, ll y2, ll x2){

    
    return (sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1-1]);
}


int main    (){

 ll n, m, q;

 cin >> n >> q;

 fora(i,1,n){
    string s;
    cin >> s;
    fora(j,1,s.size()){
        ll v = s[j-1] == '*'? 1 : 0;
        sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + v;
    }
 }

    // fora(i,0,n){
    //     fora(j,0,4){
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while(q--){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2 ;
        // cout << "QUERY" << endl;
        cout << query(y1,x1,y2,x2) << endl;
    }

    return 0;

}