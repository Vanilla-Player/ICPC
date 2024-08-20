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
ll nums[200005];
    #define K 18 // Levels
    #define oper min // Operator

ll sparse[K][1<<K]; // 2^K > n

void init_sparse(ll arr[] , ll n){
    fori(i,n){
        sparse[0][i] = arr[i];
    }
    for (int k = 1; k < K; k++)
    {
       
       for (int i = 0; i < (n - (1<<k) + 1); i++)
       {
        
        sparse[k][i] = oper(sparse[k-1][i], sparse[k-1][i + (1<<(k-1))]);
        
       }
       
    }
    
    return;
}

ll st_query(ll s, ll e){ // Remember do - 1 to the values if queries don't start at 0.

    int k=31-__builtin_clz(e - s + 1);

    e = (e-(1<<k) + 1) >= 0?e-(1<<k) + 1:0; // this new e' is the last index connected to the e parameter of the query. At level k!
                                            // . Because, e' is contain on lvl k and maybe e is not contain.

    ll ans = min(sparse[k][s], sparse[k][e]);
    return ans;
}

int main    (){

 ll n, q;

 cin >> n >> q;



 fori(i,n){
    ll num;
    cin >> num;
    nums[i] = num ;
 }

init_sparse(nums,n);

    // fori(i,n){
    //     cout << nums[i] << endl;
    // }

//  fori(i,n){
//     fora(j,0,n){
//         cout << sparse[j][i] <<" ";
//     }
//     cout << endl;
//  }

    while(q--){
        ll l, r;
        cin >> l >> r;
        // cout << "QUERY" << endl;
        cout << st_query(l-1,r-1) << endl;
    }

    return 0;

}