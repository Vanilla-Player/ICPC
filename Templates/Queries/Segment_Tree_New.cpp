
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