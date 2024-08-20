vl sum(200005,0); // typedef vector<ll> vl;
ll query(ll a , ll b){ // query(l,r) ya que movi en + 1 el index
    return sum[b] - sum[a-1];
}
// INIT EMPEZANDO DE 1 porque sum[0] = 0
fora(i,1,n){
    ll num;
    cin >> num;
    sum[i]+= num + sum[i-1];
 }