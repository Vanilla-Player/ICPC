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
    #define K 18 // Levels
    #define oper min // Operator

#define MAX_N 200000




ll ft[MAX_N + 1]; // 1 mas para tener en posicion 0 ft[0] = 0
ll nums[MAX_N + 1]; // los nums lo almaceno para calcular el valor del update
// El ft[index] contiene al menos el valor de array[index]
ll get(ll indx){ // Retorna el valor acumulado para el index
               // siempre el siguiente valor a buscar, es una disminucion por (i&-i)
    ll result = 0;
    for (ll i = indx;i; i-=(i&-i)){result+=ft[i];}
    return result;
}
ll query(ll i1, ll i2){
    return get(i2) - get(i1 - 1); // La query es como prefix sum
}

void update(ll index, ll value, ll n){// esto es el valor por el cual sumar ya sea pos o neg
                            // entonces, actualizo solo los index que lo contienen
    for(ll i = index; i <= n;i+=(i&-i)){ft[i]+=value;} // Acuerdense de actualizar el array original
                                                        // si es necesario
}
void init_ft(ll arr[],ll n){ // arr[] es el array por el cual se crean los valores
    for (ll i = 1; i <= n; i++)
    {   // Si iniciamos con update, solo necesitamos dos arrays. El original, y el FT
        update(i,arr[i],n); // i&-i es la maxima potencia de 2 que divide i
    }   // sum(k−p(k)+1,k) la realizo como el prefix sum
}

int main    (){

 ll n, q;

 cin >> n >> q;

ft[0] = 0;
 fori(i,n){
    ll num;
    cin >> num;
    nums[i+1] = num;
 }

init_ft(nums,n);

// fori(i,n+1){
//     cout << ft[i] << " ";
// }
// cout << endl;

while(q--){
    ll id, a, b;
    cin >> id >> a >> b;
    if(id == 1){
        update(a, (b - nums[a]),n);
        nums[a] = b;
        // fori(i,n+1){
        //     cout << ft[i] << " ";
        // }
        // cout << endl;
    }else{
        cout << query(a,b) << endl;
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