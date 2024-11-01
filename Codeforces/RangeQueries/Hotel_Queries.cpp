#include <bits/stdc++.h>

using namespace std;

#define fori(i,n) for(int i = 0; i < (n);i++)
#define fora(i,a,n) for(int i = (a); i <= (n);i++)
#define MAX_N 2000005
const int INF = 1e9 + 7;
#define fill(a, v) memset(a, (long long)v, sizeof(a))
#define oper max
#define ll long long


ll sgt[4*(MAX_N)]; 
ll n;

// ll query(ll a){ 

//     if(sgt[1] < a)return -1;
//     int k = 1;
//     while(k<n){
//         if(sgt[2*k]>=a)k<<=1;
//         else k<<=1,k++;
//     }
//     return k-n;
// }
// void update(ll index, ll value){
//     ll k = index + n; 
//     sgt[k] = value;
//     k>>=1;
//     while(k>=1){
//         sgt[k] = oper(sgt[2*k],sgt[2*k+1]);
//         k>>=1;
//     }
//     // for( k /= 2; k >= 1; k/=2){
        
//     // }
// }

void update(int v, int tl, int tr, int new_val, int pos){

    if(tl == tr){
        // cout << "Assign" << endl;
        // cout << "v: "<< v << endl;
        // cout << "tl: "<< tl << endl;
        // cout << "tr: "<< tr << endl;
        // cout << "new_val: "<< new_val << endl;
        // cout << "pos: "<< pos << endl; 
        sgt[v] = new_val;
        return;
    }else{

        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(v*2, tl, tm, new_val, pos);
        }else{
            update(v*2+1, tm+ 1, tr, new_val, pos);
        }
        sgt[v] = max(sgt[2*v],sgt[v*2+1]);
    }

}

int query(int v,int tl, int tr, int val){

    if(tl == tr){
        if(v == 1){
            if(sgt[1] < val){
                return INF;
            }
        }
        return (v-n);
    }
    int v1 = INF;
    int v2 = INF;
    if(sgt[v] >= val){
        int tm = (tl + tr)/2;
        if(sgt[2*v] >= val){
           v1 = query(v*2, tl, tm, val);
        }else{
            v2 = query(v*2 + 1, tm+1, tr, val);
        }
    }
    return min(v1, v2);
}


int main(){

    ll q;
    cin >> n >> q;
    ll nn = n;
    n = ceil(log2(n*1.0));
    n = 1<<n;
    cout << "n: " << n << endl;
    cout << "nn: "<< nn << endl;
    fori(i,nn){
        ll hotel;
        cin >> hotel;
        update(1,0, n - 1,hotel,i);
    }
    // fori(i,4*n){
    //     cout << sgt[i] << " " ;
    // }
    // cout << "\n";
    while(q--){
        ll cap;
        cin >> cap;
        // ll res = query(cap);
        ll res = query(1,0,n-1,cap);
        if(res == INF){
            cout << "0" << " ";
        }else{
            cout << res + 1 << " ";
        }
        if(res < INF){
            ll value = sgt[res + n] - cap;
            update(1,0,n-1,value, res);
        }    
    }
    cout << endl;
}