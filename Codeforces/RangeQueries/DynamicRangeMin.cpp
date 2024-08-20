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

    
    const int MOD = 1e9 + 7;
    const int MAXN = 1e6 + 3;

    #define _ % MOD
    #define __ %= MOD

    #define each(it, s) for (vit it = s.begin(); it != s.end(); ++it)
    #define sortAsc(v) sort(v.begin(), v.end())
    #define sortDesc(v) sort(v.begin(), v.end(), greater<auto>())
    #define fill(a, v) memset(a, (long long)v, sizeof(a))

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
    #define K 18 // Levels
    #define oper min // Operator

#define MAX_N 200000
const int INF = 1e9 + 7;

ll sgt[2*(MAX_N+1)]; // 1 mas para tener en posicion 0 sgt[0] = 0
ll nums[MAX_N + 1]; // los nums lo almaceno para calcular el valor del update

ll query(ll a , ll b, ll n){
    a += n; b+=n;
    ll r = INF;
    while(a<=b){
        if(a%2 == 1) r = min(sgt[a++],r);
        if(b%2 == 0) r = min(sgt[b--],r);
        a/=2; b/=2;
    }
    return r;
}

void update(ll index, ll value, ll n){// index del elemento en el array original, valor a cambiar 
                                        // y longitud array
    ll k = index + n; // index de el elemento en el sgt es k empezando desde + n
    sgt[k] = value;
    for( k /= 2; k >= 1; k/=2){
        sgt[k] = min(sgt[2*k],sgt[2*k+1]);
    }
}
void init_sgt(ll arr[],ll n){ // arr[] es el array por el cual se crean los valores
    for (ll i = 0; i < n; i++)
    {   // Si iniciamos con update, solo necesitamos dos arrays. El original, y el SGT
        update(i,arr[i],n); 
    }   
}

int main    (){

 ll n, q;

 cin >> n >> q;

 fill(sgt,INF);
 fill(nums,INF);

 fori(i,n){
    ll num;
    cin >> num;
    nums[i] = num;
 }

init_sgt(nums,n);

// fora(i,1,2*n){
//     cout << sgt[i] << " ";
// }
// cout << endl;

while(q--){
    ll id, a, b;
    cin >> id >> a >> b;
    if(id == 1){
        update(a-1, b,n);
        nums[a-1] = b;
        // fora(i,1,2*n){
        //     cout << sgt[i] << " ";
        // }
        // cout << endl;
    }else{
        cout << query(a-1,b-1, n) << endl;
    }
}
// 8 4
// 10 9 6 10 10 3 6 7

// 1 1 6
// 1 2 5
// 1 3 7
// 1 4 4
// 1 5 6
// 1 6 2
// 1 7 7
// 1 8 7
// 2 1 1 // 6
// 2 1 2 // 11


    return 0;

}