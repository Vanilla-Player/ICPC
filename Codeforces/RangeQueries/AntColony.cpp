#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define fori(i,n) for(int i = 0; i < (n);i++)
#define fora(i,a,n) for(int i = (a); i <= (n);i++)
#define MAX_N 100050
#define fill(a, v) memset(a, (long long)v, sizeof(a))
#define oper max
#define int long long
const int INF = 1e9 + 7;

int sgt[4*MAX_N];

map<int, vector<int> > m;

int ants[MAX_N];

int n,t,nn;

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}


void build(int v, int tl , int tr){
    if(tl == tr){
        sgt[v] = ants[tl];
        return;
    }
    // int tm = (tl+tr)/2;
    int tm = (tl + tr) >> 1;
    build((v << 1) + 1, tl, tm);
    build((v << 1) + 2, tm + 1, tr);
    sgt[v] = gcd(sgt[(v << 1) + 1], sgt[(v << 1) + 2]);
}

int query(int v, int tl, int tr, int l, int r){
    
    if(tl == l && tr == r) return sgt[v];
    int tm = (tl + tr) >> 1;
    if(r <= tm){
        return query((v << 1) + 1, tl, tm, l, r);
    }else if(tm < l){
        return query((v << 1) + 2, tm + 1, tr, l, r);
    }else{
        return gcd(query((v << 1) + 1, tl, tm, l, tm),query((v << 1) + 2, tm + 1, tr, tm + 1, r));
    }
}

int countAnts(vector<int> &v, int x ){
  int l = -1, r = (int)v.size();
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (v[mid] <= x) l = mid;
        else r = mid;
    }
    return l + 1;
}

int numberOfAnts(int l, int r, int x){
    return countAnts(m[x],r) - countAnts(m[x],l-1);
}

signed main(){

    cin >> n;

    int nn = n;
    // n = ceil(log2(n*1.00));
    // n = 1<<n;


    fora(i,1,nn){
        cin >> ants[i];
    }

    build(0,1,n);


    fora(i,1,nn){
        m[ants[i]].push_back(i);
    }

    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int ans = (r - l + 1) - numberOfAnts(l, r, query(0,1,n,l,r));
        cout << ans << endl;
    }


}

