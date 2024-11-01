#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef __uint128_t u128;
#define ford(i,a,n) for(int i = (a); i >= (n); i++)

template <typename T>
using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;
#define pb push_back
#define mp make_pair


#define ll long long

#define dprint(v) cout << #v"=" << v << endl //;)
#define fill(a, v) memset(a, v, sizeof(a))

#define fora(i,a,n) for(ll i = (a); i <= (n); i++)
#define fori(i,n) for(ll i = 0; i < (n); i++)
const int MAXN = 100005;
    ll INF = 1e12;


vector<vector<pair<ll,int> > > G(MAXN);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int p,g;
    cin >> p >>g;


    fori(i,m){
        int from, to;
        ll w;
        cin >> from >> to >> w;
        G[from].pb(mp(w,to));
        G[to].pb(mp(w,from));
    }


    rpriority_queue<pair<ll,int> > q;
    vector<ll>P_d(n+1,INF);
    

    q.push({0,p});
    while(!q.empty()){
        auto pr = q.top();
        int node = pr.second;
        ll weight = pr.first;
        q.pop();

        if(P_d[node] != INF)continue;
        
        P_d[node] = weight;
        
        if(node == g)continue;
        for(auto v: G[node]){
            int to = v.second;ll w = v.first;
            if(INF == P_d[to]){
                q.push({(weight + w),to});
            }
        }

    }

    
    vector<ll>G_d(n+1,INF);
    
    // cout  << "RESULTADO P[g]: " << P_d[g] << "\n";
    
    q.push({0,g});
    
    while(!q.empty()){
        auto pr = q.top();
        int node = pr.second;
        ll weight = pr.first;
        q.pop();
        if(G_d[node] != INF)continue;
        G_d[node] = weight;

        for(auto v: G[node]){

            int to = v.second;ll w = v.first;
            // dprint(to);
            ll aaa = P_d[g] + weight + w;
            // dprint(aaa);
            // dprint(P_d[to]);
            if(1LL*(P_d[g] + weight + w) < P_d[to] && G_d[to] == INF){
                // cout << "PUSHH\n"; 
                q.push({(weight + w),to});
            }
        }
    }
    vector<int> ans;
    fora(i,1,n){    
        // dprint(i);
        //     dprint(P_d[i]);
        //     dprint(G_d[i]);
        if(P_d[g] == G_d[i]){
            
            ans.pb(i);
        }
    }

    if(ans.size() < 1){
        cout << "*\n";
        return 0;
    }

    for(auto v: ans){
        cout << v << " ";
    }
    cout << "\n";
    return 0;

}