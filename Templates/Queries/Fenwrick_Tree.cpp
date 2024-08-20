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

// update(a, (b - nums[a]),n); ejemplo de update (b-nums[a]) es el valor por el cual actualizar el FT
// nums[a] = b; actualizacion