
#define MAX_N 200000
const int INF = 1e9 + 7;
#define fill(a, v) memset(a, (long long)v, sizeof(a))
#define oper min
ll sgt[2*(MAX_N+1)]; // 1 mas para tener en posicion 0 sgt[0] = 0
ll nums[MAX_N + 1]; // los nums lo almaceno para calcular el valor del update
// Rellenar porque sino tenes 0 y si buscas minismo, te caga
//  fill(sgt,INF); 
//  fill(nums,INF);
//En caso de ser max cambiar por 0
ll query(ll a , ll b, ll n){ // query(a-1,b-1, n) Porque index de input esta + 1
    a += n; b+=n;
    ll r = INF;
    while(a<=b){
        if(a%2 == 1) r = oper(sgt[a++],r);
        if(b%2 == 0) r = oper(sgt[b--],r);
        a/=2; b/=2;
    }
    return r;
}
void update(ll index, ll value, ll n){// Ej update(a-1, b,n);  nums[a-1] = b; Actualizar valor array
                                        // index del elemento en el array original, valor a cambiar 
                                        // y longitud array
    ll k = index + n; // index de el elemento en el sgt es k empezando desde + n
    sgt[k] = value;
    for( k /= 2; k >= 1; k/=2){
        sgt[k] = oper(sgt[2*k],sgt[2*k+1]);
    }
}
void init_sgt(ll arr[],ll n){ // arr[] es el array por el cual se crean los valores
    for (ll i = 0; i < n; i++)
    {   // Si iniciamos con update, solo necesitamos dos arrays. El original, y el SGT
        update(i,arr[i],n); 
    }   
}