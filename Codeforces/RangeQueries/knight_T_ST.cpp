#include <bits/stdc++.h>

using namespace std;

int st[10500000];
int ans[3000005];
int R = 0;

void update(int v, int tl, int tr, int l ,int r, int w){

    if(st[v] == -1)return;

    if(tr < l || tl > r ){
        return;
    }

    if( tl == tr){
       ans[tl] = w;
       if(tl != w){
        st[v] = -1;
       }
       return;
    }

        int tm = (tl+tr) / 2;
        update(v*2, tl, tm, l,  r, w);
        update(v*2+1, tm + 1,tr ,l, r, w);
    
    st[v] = max(st[v*2], st[v*2+1]); // clave

}

int main(){

    int n,m;

    cin >> n >> m;

    int q = m;
    int winner = 0;
    while(q--){

        int l, r, x;
        cin >> l >> r >> x;
        R = r;
        update(1, 0, n - 1, l-1, r - 1,x-1);
        winner = x - 1;
    }

    for(int i = 0; i < n; i++){
        if(winner == i){
            cout << "0" << " ";
        }else{
            cout << ans[i] + 1 << " ";
        }
    }
    cout << endl;

}


 