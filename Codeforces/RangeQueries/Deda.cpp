#include <bits/stdc++.h>

using namespace std;

#define fori(i,n) for(int i = 0; i < (n);i++)
#define fora(i,a,n) for(int i = (a); i <= (n);i++)
#define MAX_N 2000005
const int INF = 1e9 + 7;
#define fill(a, v) memset(a, (long long)v, sizeof(a))
#define oper max
#define int long long

int sgt[4*(MAX_N)];
int n,q,nn;

void build(int v, int tl, int tr){

    if(tl == tr){
        sgt[v] = INF;
        
    }else{
        int tm = (tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm + 1, tr);
        sgt[v] = min(sgt[v*2], sgt[v*2+1]);
    }

}

void update(int v, int tl, int tr, int pos, int new_value){

    if(tl == tr){
        sgt[v] = new_value;
        
    }else{
        int tm  = (tl+tr)/2;

        if(pos <= tm){
            update(v*2, tl, tm, pos, new_value);
        }else{
            update(v*2+1, tm+1, tr, pos, new_value);
        }
        sgt[v] = min(sgt[v*2], sgt[v*2+1]);
    }

}

int query(int v, int tl , int tr, int l, int r){

    if(l > r){
        return INF;
    }    
    if( l == tl && r == tr){
        return sgt[v];
    }else{
        int tm = (tl+tr)/2;
        int leftAns = query(2*v, tl, tm, l, min(tm, r));
        int rightAns = query(2*v + 1, tm+1, tr, max(l, tm+1), r);
        return min(leftAns, rightAns);
    }


}



signed main(){

    cin >> n >> q;
    build(1,0,n-1);

    while(q--){
        char id;
        cin >> id;
        if(id == 'M'){
            int a, x;
            cin >> x >> a;
            update(1, 0, n-1,a-1, x);
        }else{
            int b, y;
            cin >> y >> b;
            int l = b - 1, r = n - 1, ans = n + 1;
            while(l <= r){
                int child  = (l+r)/2;
                int min_stop = query(1,0,n-1,l,child);    
                if(min_stop <= y){
                    ans = min(ans,child);
                    r = child - 1;
                }else{
                    l = child + 1;
                }
            }

            if(ans == n + 1)
                cout << "-1\n";
            else
                cout << ans + 1 << "\n";

        }

    }

}