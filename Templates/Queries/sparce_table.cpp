    #define K 18 // Levels
    #define oper min // Operator
ll sparse[K][1<<K]; // 2^K > n
void init_sparse(ll arr[] , ll n){
    fori(i,n){ // for (int i = 0; i < (n); ++i)
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
ll st_query(ll s, ll e){ // Recordar que el input puede estar corrido un valor mas entonces st_query(l-1,r-1)
    // El k es el maximo nivel que contiene el min(s,i) y min(i+1,e)
    // puede ser que k contena directo min(s,e)
    // ej si hago st_query(0,7) consigo k=3 que directamente contiene min(s,e)
    int k=31-__builtin_clz(e - s + 1);// log2 (s+1) porque no incluimos a s
    e = (e-(1<<k) + 1) >= 0?e-(1<<k) + 1:0; // e' es el valor de e conectado a el nivel k
    ll ans = min(sparse[k][s], sparse[k][e]);
    return ans;
}
// example query 1 7 => st_query(0,6)!!