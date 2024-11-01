#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 1e6 + 10;


int d[MAXN];

void criva(){

    for (int i = 1; i < MAXN; i++)
    {
        for (int j = i; j < MAXN; j+=i)
        {
            d[j]++;
        }
        
    }
    
}

struct datinha{
    ll sum, open;
    datinha (): sum(0), open(0){}
    datinha (ll sum, ll open): sum(sum), open(open){}
    datinha operator +(const datinha &node) const{
        return datinha(sum + node.sum, open + node.open);
    }
};

datinha sgt[4*(MAXN)];
ll n,m, a[MAXN];

datinha build(ll v, ll tl , ll tr){
    if(tl == tr){
        sgt[v] = datinha(a[tl], d[a[tl]] != a[tl]);
        return sgt[v];
    }else{
        ll tm = (tl+tr)/2;
        return sgt[v] = build(v*2, tl, tm) + build(v*2+1, tm + 1, tr);
    }
}

void update(ll v, ll tl , ll tr, ll l , ll r){
    if(r < tl ||  tr < l || !sgt[v].open) return;
    if(tl == tr){
        // cout << "tl: " << tl << "\n";
        // cout << "a[tl]: " << a[tl] << "\n";
        // cout << "d[a[tl]]: " << d[a[tl]] << "\n";
        a[tl] = d[a[tl]];
        sgt[v] = datinha(a[tl], d[a[tl]] != a[tl]);
        return;
    }
    ll tm = (tl+tr)/2;
    update(v*2, tl ,tm, l, r);
    update(v*2 + 1, tm + 1 ,tr, l, r);
    sgt[v] = sgt[v*2] + sgt[v*2 + 1];
    return;
}

datinha query(ll v, ll tl, ll tr, ll l , ll r){
    if(l <= tl && tr <= r) return sgt[v];
    if(tr < l || r < tl ){
      return datinha();  
    } 
    ll tm = (tl+tr)/2;
    return query(v*2, tl ,tm, l, r) + query(v*2 + 1, tm + 1 ,tr, l, r);
}


int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    criva();
    // cout << "d[10]: " << d[10] << "\n"; 
    cin >> n >> m;
    ll nn = n;
    n = ceil(log2(n*1.00));
    n = 1<<n;
    for (int i = 0; i < nn; i++)
    {
        cin >> a[i];
    }

    build(1,0,n-1);

    // for(int i = 1; i <= 4*n; i++){
    //     cout << sgt[i].sum << " ";
    // }
    // cout << "\n";
    while (m--)
    {

        ll op, l ,r;
        cin >> op >> l >> r;
        if(op == 1){
            update(1,0, n-1, l-1, r-1);

        }else{
            cout << query(1,0, n-1, l-1, r-1).sum << endl;
        }
    }
    
    
}