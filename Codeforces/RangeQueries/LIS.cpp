#include <bits/stdc++.h>

using namespace std;

#define fori(i,n) for(int i = 0; i < (n);i++)
#define fora(i,a,n) for(int i = (a); i <= (n);i++)
#define MAX_N 20050
const int INF = 1e9 + 7;
#define fill(a, v) memset(a, (long long)v, sizeof(a))
#define oper max
#define ll long long

int sgt[4*MAX_N];

int n;
int nums[MAX_N];


void update(int v, int tl, int tr, int l , int r, int pos, int value){
    if( r < tl ||tr < l)return;

    if(tl == tr){
        sgt[v] = value;
        return;
    }
    int tm = (tl+tr)/2;
    if(pos <= tm){
        update(v*2,tl,tm, l,r, pos, value);
    }else{
        update(v*2 + 1,tm + 1,tr, l,r, pos, value);
    }
    sgt[v] = max(sgt[v*2], sgt[v*2 + 1]);
    return;
}

int query(int v, int tl, int tr, int l , int r){

    if(r < tl || tr < l) return 0;

    if(tl == l && tr == r){
        return sgt[v];
    }
    int tm = (tr + tl)/2;

    return max(query(2*v, tl, tm, l, min(r, tm)), query(2*v + 1, tm + 1, tr, max(tm+1,l), r));
}


int main(){

    cin >> n;
    
    fori(i,n){
        cin >> nums[i];
    }

    fori(i,n){
        // cout << "query" << endl;
        int l = query(1,0,n,0,nums[i] - 1);
        // cout << "upadate" << endl;
        update(1,0,n,0,n,nums[i],l+1);
    }

    cout << query(1,0,n,0,n);


}

// 8
// 10 9 2 5 3 7 101 18