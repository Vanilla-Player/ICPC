#include <bits/stdc++.h>
 
 
using namespace std;
 
 
#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define int long long

const int MAXN = 100000 + 5;
 
// Para printear Variables
#define  dprint(v) cout << #v"=" << v << endl //;) 
// Si lleva ")" al final

int sgt[4*(MAXN)];
string s;
int q;


void update(int v, int tl, int tr,int pos, int value){

    if (tl == tr){
        sgt[v] = value;
        return;
    }
    int tm = (tr + tl)/2;
    if(pos <= tm){
        update(2*v, tl, tm, pos, value);
    }else{
        update(2*v + 1, tm+ 1, tr, pos, value);
    }
    sgt[v] = (sgt[v*2] | sgt[v*2 + 1]);
    return;
}

int query(int v, int tl, int tr, int l, int r){
    // cout << "v: " << v << endl;

    if(l <= tl && tr <= r){
        return sgt[v];
    }

    if(r < tl || tr < l )return 0;
    
    int tm = (tl+tr)/2;
    return (query(2*v, tl, tm, l, min(r,tm)) | query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> s;
    cin >> q;

    int n = s.size();
    int nn = n;
    n = ceil(log2(n*1.00));
    n = 1<<n;


    fori(i, nn){
        int value = s[i] - 'a';
        update(1, 0, n-1, i, 1<<value);
    }

    // fori(i, 4*n){
    //     cout << sgt[i].diff << " ";
    // }
    int id;
    while(q--){
        cin >> id;
        if(id == 1){
            char c;
            int pos, value;
            cin >> pos >> c;
            value = c - 'a';
            update(1,0,n-1,pos-1,1<<value);
            // fori(i, 4*n){
            //     cout << sgt[i].diff << " ";
            // }
            // cout << endl;
        }else{
            int l,r;
            cin >> l >> r;
            cout << __builtin_popcount(query(1, 0, n-1, l-1,r-1)) << endl;
            // cout << "Query: " << l << " " << r << endl;
        }
    }

}