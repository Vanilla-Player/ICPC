ll sgt[2*(MAX_N+1)]; // 1 mas para tener en posicion 0 sgt[0] = 0
ll nums[MAX_N + 1]; // los nums lo almaceno para calcular el valor del update

// Recordar usar los index originales del array. Es decir empezando desde 0
// al reves de Fenwrick Tree. El cual muevo en 1 el index del array
ll sum(ll a , ll b, ll n){ // Ej sum(a-1,b-1, n) index input estan + 1
    a += n; b+=n;       
    ll r = 0;
    while(a<=b){
        if(a%2 == 1) r+= sgt[a++];
        if(b%2 == 0) r+= sgt[b--];
        a/=2; b/=2;
    }
    return r;
}
void update(ll index, ll value, ll n){// Ej  update(a-1, (b - nums[a-1]),n) 
                                        //resto uno porque el index del input es +1
    ll k = index + n; // index de el elemento en el sgt es k empezando desde + n
    sgt[k]+=value;
    for( k /= 2; k >= 1; k/=2){
        sgt[k] = sgt[2*k] + sgt[2*k+1];
    }
}
void init_sgt(ll arr[],ll n){ // arr[] es el array por el cual se crean los valores
    for (ll i = 0; i < n; i++)
    {   // Si iniciamos con update, solo necesitamos dos arrays. El original, y el SGT
        // Aca no resto porque uso el array que empieza desde 0
        update(i,arr[i],n); 
    }   
}