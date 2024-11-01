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
 
// Para printear Variables
#define  dprint(v) cout << #v"=" << v << endl //;) 
// Si lleva ")" al final
 
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 200009;

int sgt[4*(MAXN)];
int dp[MAXN];
int x[MAXN], y[MAXN], c[MAXN];
vector<int> byx[MAXN];
int n;
map<int, int> nums;
map<pair<int,int>, int> donation;


void update(int v, int tl, int tr, int pos, int value){

    // if( r < tl ||tr < l)return;

    if(tl == tr){
        sgt[v] = max(value,sgt[v]);
        return;
    }
    int tm = 1LL*(tl+tr)/2;
    if(pos <= tm){
        update(2*v, tl, tm,  pos, value);
    }else{
        update(2*v + 1, tm+1, tr,  pos, value);
    }

    sgt[v] = max(sgt[2*v], sgt[2*v+1]);

    return;

}

int query(int v, int tl, int tr, int l, int r){

    if(tr < l || r < tl) return 0;

    if(tl == l && tr == r){
        return sgt[v];
    }
    int tm = 1LL*(tl+tr)/2;

    return max(query(2*v, tl, tm, l, min(r, tm)), query(2*v + 1, tm + 1, tr, max(l, tm+ 1), r));

}


signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;

    fori(i,n){
        cin >> x[i] >> y[i] >> c[i];
        nums[x[i]] = 0;
        nums[y[i]] = 0;
    }

    int cnt = 0;
    for(auto &p : nums){
        p.se = cnt;
        cnt++;
    }

    
    fori(i,n){
        x[i] = nums[x[i]];
        y[i] = nums[y[i]];
        donation[{x[i],y[i]}] += c[i];
    }
    
    int n = 0;
    for (auto p :donation)
    {
        x[n] = p.fi.fi;
        y[n] = p.fi.se;
        c[n] = p.se;
        n++;
    }

    fori(i,n){
        byx[x[i]].push_back(i);
    }

    n = ceil(log2(cnt*1.00));
    n = 1<<n;

    int ans = 0;
    fori(xt, cnt){
        for(int i : byx[xt]){
            dp[i] = c[i] + query(1,0, n-1,0, y[i] - 1);
            
            ans = max(ans,dp[i]);
        }

        for(int i : byx[xt]){
            update(1,0,n-1,y[i], dp[i]);
            
        }
    }
    
    cout << ans << endl;
    

}