    #include <bits/stdc++.h>
    using namespace std;


    typedef pair<int, int> ii;
    typedef vector<int> vi;
    typedef vector<int> vl;
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

    #define int long long

#define MAX_N 200000



#define  dprint(v) cout << #v"=" << v << endl //;) 

int t[4*(MAX_N+1)]; // 1 mas para tener en posicion 0 sgt[0] = 0
int nums[MAX_N + 1]; // los nums lo almaceno para calcular el valor del update

void build_tree(int a[], int v, int tl, int tr){

    if(tl == tr){
        t[v] = a[tl];
    }else{
        int tm = (tl + tr)/2;
        build_tree(a, 2*v, tl, tm);
        build_tree(a, 2*v+1, tm + 1, tr);
        t[v] = t[2*v] + t[2*v+1];
    }

}

int sum(int v, int tl, int tr, int l, int r){
    if(l > r){
        return 0;
    }
    if(l == tl && r  == tr){
        return t[v];
    }
    int tm = (tl + tr) /2;
    return sum(2*v, tl, tm, l, min(r, tm)) + sum(2*v + 1, tm + 1, tr, max(l,tm + 1), r); 
}

void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        t[v] = new_val;
    }else{
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(2*v, tl, tm, pos, new_val);
        }else{
            update(2*v+1, tm+1, tr, pos, new_val);
        }

        t[v] = t[2*v] + t[2*v+1];

    }

}

// int sum(int a , int b, int n){
//     a += n; b+=n;
//     int r = 0;
//     while(a<=b){
//         if(a%2 == 1) r+= sgt[a++];
//         if(b%2 == 0) r+= sgt[b--];
//         a/=2; b/=2;
//     }
//     return r;
// }

// void update(int index, int value, int n){// index del elemento en el array original, valor a cambiar 
//                                         // y longitud array
//     int k = index + n; // index de el elemento en el sgt es k empezando desde + n
//     sgt[k]+=value;
//     for( k /= 2; k >= 1; k/=2){
//         sgt[k] = sgt[2*k] + sgt[2*k+1];
//     }
// }
// void init_sgt(int arr[],int n){ // arr[] es el array por el cual se crean los valores
//     for (int i = 0; i < n; i++)
//     {   // Si iniciamos con update, solo necesitamos dos arrays. El original, y el SGT
//         update(i,arr[i],n); 
//     }   
// }

signed main    (){

 int n, q;

 cin >> n >> q;

 fori(i,n){
    int num;
    cin >> num;
    nums[i] = num;
 }

// init_sgt(nums,n);

build_tree(nums, 1, 0, n - 1);

// fora(i,1,4*n){
//     cout << t[i] << " ";
// }
// cout << endl;

while(q--){
    int id, a, b;
    cin >> id >> a >> b;
    if(id == 1){
        // update(a-1, (b - nums[a-1]),n);
        update(1, 0, n - 1, a-1, b);
        
        nums[a-1] = b;
    //     fora(i,1,2*n){
    //         cout << sgt[i] << " ";
    //     }
    //     cout << endl;
    }else{
        cout << sum(1, 0, n-1, a - 1, b - 1) << endl;
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