// https://codeforces.com/problemset/problem/1791/F
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef __uint128_t u128;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
 
// Metodos para vectores, sets y maps
#define each(it, s) for (vit it = s.begin(); it != s.end(); ++it)
#define sortAsc(v) sort(v.begin(), v.end())
#define sortDesc(v) sort(v.begin(), v.end(), greater<auto>())
#define fill(a, v) memset(a, v, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
// Iterar
#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
// Para printear Variables
#define  dprint(v) cout << #v"=" << v << endl //;) 
 
const int MAXN = 200005;
 
struct Vertex{
    bool to_update = false;
    ll update_times = 0;
    ll number = 0;
    ll sum = 0;
};
 
vector<Vertex> t;
vector<ll> arr;
 
ll digit_sum(ll n){
    ll sum = 0;
    while(n){
        sum += n %10;
        n/=10;
    }
    return sum;
}
 
 
void build(ll v, ll tl ,ll tr){
    
    if(tl == tr){
        Vertex new_v;
        new_v.number = arr[tl];
        
        ll sum = arr[tl];
       
        new_v.sum = sum;
        t[v] = new_v;
        return;
    }
    ll tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(1+2*v, tm+1, tr);
    return;
}
 
void push(ll v){
    
    if(t[v].to_update){
        t[2*v].to_update = true;
        t[2*v].update_times+=t[v].update_times;
        t[2*v].update_times = t[2*v].update_times > 2?2:t[2*v].update_times;
        t[1+2*v].to_update = true;
        t[1+2*v].update_times+= t[v].update_times;
        t[1+2*v].update_times = t[1+2*v].update_times > 2?2:t[1+2*v].update_times;
        t[v].to_update = false;
        t[v].update_times = 0;
    }
    return;
}
 
void update_vertex(ll v){
    if(t[v].number <= 9)return;
    fori(i,t[v].update_times){
        
        ll sum = digit_sum(t[v].number);
        
        t[v].number = sum;
        t[v].sum = sum;
    }
    return;
 
}
 
ll query(ll v, ll tl, ll tr, ll l, ll r,ll pos){
 
    if(tr < l || tl > r)return 0;
    if(tl == tr){
        
        if(t[v].to_update){
            update_vertex(v);
            t[v].to_update = false;
            t[v].update_times = 0;
        }
        
        return t[v].sum;
    }
    push(v);
    ll tm = (tl+tr)/2;
    ll ans;
    if(pos <= tm ){
        ans = query(2*v, tl, tm, l, min(tm, r),pos);
    }else{
        ans = query(1+2*v, tm+1, tr, max(tm+1,l), r,pos);
    }
    return ans;
 
}
 
void update(ll v, ll tl, ll tr, ll l, ll r){
    if(tr < l || tl > r)return;
 
    if(tl == l && tr == r){
        t[v].to_update = true;
        t[v].update_times+= t[v].update_times < 2?1:0;
        return;
    }
    ll tm = (tl+tr)/2;
    push(v);
    update(v*2, tl, tm, l, min(r, tm));
    update(1+v*2,tm+1, tr, max(l,tm+1),r);
    return;
}
 
void solve(){
    ll n,q;
    cin >> n >> q;
 
    ll nn = n;
    n = ceil(log2(n*1.00));
    n = 1 << n;
    t.resize(4*n, Vertex());
    arr.resize(n,0);
    fori(i,nn){
        cin >> arr[i];
    }
    build(1,0,n-1);
 
    // fori(i,2*n){
    //     cout << t[i].sum << " ";
    // }
    // cout << "\n";
 
    while(q--){
        ll id;
        cin >> id;
        if(id == 1){
            ll l, r;
            cin >> l >> r;
            l--;r--;
            update(1,0,n-1,l,r);
 
        }else{
            ll pos;
            cin >> pos;
            
            ll ans = query(1,0,n-1,0,n-1,pos - 1);
            cout << ans << "\n";
 
        }
    }
}
 
int main(){
 
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}