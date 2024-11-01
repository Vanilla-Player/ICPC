#include <bits/stdc++.h>

using namespace std;

#define fori(i,n) for(int i = 0; i < (n);i++)
#define fora(i,a,n) for(int i = (a); i <= (n);i++)
#define MAX_N 2000005
const int INF = 1e9 + 7;
#define fill(a, v) memset(a, (long long)v, sizeof(a))
#define oper max
#define int long long



struct datinha{
    int sum,suf,pre,maxi;

    datinha(){
        sum = 0;
        suf = 0;
        pre = 0;
        maxi = 0;
    }
    datinha(int val){
        sum = val;
        suf = val;
        pre = val;
        maxi = val > 0? val : 0;
    }
};

datinha sgt[4*(MAX_N)];
int arr[MAX_N];
int n,q,nn;

datinha combine(datinha leftn, datinha rightn){
    datinha new_data = datinha();
    new_data.pre = max(leftn.pre, leftn.sum + rightn.pre); 
    new_data.suf = max(leftn.suf + rightn.sum,rightn.suf); 
    new_data.sum = leftn.sum + rightn.sum;
    new_data.maxi = max({leftn.maxi, rightn.maxi, leftn.suf + rightn.pre}); 
    int var = 0;
    new_data.maxi = max(new_data.maxi, var);

    return new_data;
}

void build(int v, int tl, int tr){

    if(tl == tr){

        sgt[v] = datinha(-INF);
        
    }else{
        int tm = (tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm + 1, tr);
        sgt[v] = combine(sgt[v*2], sgt[v*2+1]);
    }

}

void update(int v, int tl, int tr, int pos, int new_value){

    if(tl == tr){

        sgt[v] = datinha(new_value);
        
    }else{
        int tm  = (tl+tr)/2;

        if(pos <= tm){
            update(v*2, tl, tm, pos, new_value);
        }else{
            update(v*2+1, tm+1, tr, pos, new_value);
        }
        
        sgt[v] = combine(sgt[v*2], sgt[v*2+1]);
    }

}

datinha query(int v, int tl , int tr, int l, int r){

    if(r < tl ||  tr < l){
        return datinha();
    }    
    if( l == tl && r == tr){
        return sgt[v];
    }else{
        int tm = (tl+tr)/2;
        datinha leftAns = query(2*v, tl, tm, l, min(tm, r));
        datinha rightAns = query(2*v + 1, tm+1, tr, max(l, tm+1), r);
        return combine(leftAns, rightAns);
    }


}


signed main(){

    cin >> n >> q;

    int nn = n;
    n = ceil(log2(n*1.00));
    n = 1<<(n);

    build(1,0,n - 1);

    fori(i,nn){
        cin >> arr[i];
        update(1,0,n-1,i,arr[i]);
    }

    while(q--){
        int pos,val;
        cin >> pos >> val;

        update(1,0,n-1,pos-1,val);

        cout << query(1,0,n-1,0,n-1).maxi << "\n";
    }



}