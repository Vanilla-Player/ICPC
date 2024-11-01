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

const int MAXN = 30005;
 
// Para printear Variables
#define  dprint(v) cout << #v"=" << v << endl //;) 
// Si lleva ")" al final


struct node{
    int l,r, q_pos, pos, value, type;

};

bool comp(node x, node y){

    if(x.value != y.value) return x.value > y.value;
    return x.type > y.type;
}

int sgt[4*(MAXN)];
vector<node> arr;


int n,q;


void update(int v, int tl, int tr, int pos, int val){
    
    if(tl == tr){
        sgt[v] = val;
        return;
    }
    int tm = (tl+tr)/2;
    if(pos <= tm){
        update(2*v, tl, tm, pos, val);
    }else{
        update(2*v + 1, tm + 1, tr, pos, val);
    }
    
    sgt[v] = sgt[2*v] + sgt[2*v+1];
    return;

}

int query(int v, int tl, int tr, int l, int r){
    if(r < tl || tr < l){
        return 0;
    }
    if(l <= tl && tr <= r){
        
        return sgt[v];
    }
    int tm = (tl+tr)/2;
    
    int l_ans = query(2*v, tl,tm, l , min(tm,r));
    int r_ans = query(2*v + 1, tm+1,tr, max(tm+1,l),r);
    
    return l_ans + r_ans;
}


signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n ;

    int nn = n;
    // n = ceil(log2(n*1.00));
    // n = 1<<n;

    fori(i, nn){

        node t;
        int val;
        cin >> val;

        t.value = val;
        t.pos = i;
        t.type = 1;
        arr.pb(t);
    }


    // fora(i,1,7){
    //     cout << "sgt :" << i << endl;
    //     for (const int &elem : sgt[i]) {
    //         cout << elem << " ";
    //     }
    //     cout << endl;
    // }

    cin  >> q;
    int cnt = 0;
    while(q--){
        int l ,r, k;
        cin >> l >> r >> k;
        node t;
        t.value = k;
        t.type = 2;
        t.l = l;
        t.r = r;
        t.q_pos = cnt;

        arr.pb(t);
        cnt++;
    }

    int ans[cnt];

    sort(arr.begin(), arr.end(), comp);

    for(node t: arr){

        if(t.type == 1 ){
            update(1, 0, n - 1, t.pos, 1);
        }else{
            ans[t.q_pos] = query(1, 0, n-1, t.l-1, t.r-1);
        }
    }

    for(auto a: ans){
        cout << a << endl;
    }

}


