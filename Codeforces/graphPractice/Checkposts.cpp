#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
typedef long long ll;
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
// Si lleva ")" al final

const int MAXN = 100005;
const int MOD = 1e9+7;
const int INF = 1e9+7;

vector<int> adj[MAXN];
int ids[MAXN];
int low[MAXN];
ll costs[MAXN];
int cnt[MAXN];
vector<vector<int> >comps(MAXN);
ll mini[MAXN];
stack<int> in_process;
vector<int> stackMember(MAXN);
map<ii,int>conexion; 

int id = 0;

void tarjan(int node){
    id++;
    low[node] = ids[node] = id;
    in_process.push(node);
    stackMember[node] = 1;
    
    for(auto v: adj[node]){
        if(ids[v] == -1){
            tarjan(v);
            low[node] = min(low[node], low[v]);
        }  
       
        if(stackMember[v]){ 
            low[node] = min(low[node], ids[v]);
        }

    }
    
    // dprint(id);
    if(low[node] == ids[node]){
    
        while(node != in_process.top()){
            // cout << "into\n"; 
            int n = in_process.top();
            // dprint(n); 
            // dprint(stackMember[n]); 
            // dprint(comps[node].size()); 
            
            stackMember[n] = 0;
            // cout << "ACT" << endl;
            comps[node].pb(n);
            // cout << "Push\n";
            in_process.pop();
            // cout << "POP\n";
            // dprint(in_process.top());
        }
        // cout << "after\n" ;
       
        comps[node].pb(in_process.top());
        stackMember[node] = 0;
        in_process.pop();
    }

}


int main(){

    int n,m;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        ids[i] = -1;
        low[i] = -1;
        cin >> costs[i];
    }


    cin >> m;
    fori(i,m){
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    fori(i,n){
        if(ids[i + 1] == -1){
            tarjan(i + 1);
        }
    }

    fill(mini,INF);
    fora(i,1,n){
        if(comps[i].size() == 0)continue;
        
        for(auto node: comps[i]){
            int w = costs[node];
            if(mini[i] > w){
                mini[i] =w;
                cnt[i] = 1;
                continue;
            }
            if(w == mini[i]){
                cnt[i]++;
            }

        }
        
    }
    ll total = 0;
    ll formas = 1;
    fora(i,1,n){
        if(comps[i].size() == 0)continue;
        // dprint(i);
        total+=mini[i];
        if(cnt[i] == 0)continue;
        formas *= 1LL*(cnt[i]);
        formas %= MOD;
    }
    
    cout << total << " " << formas << endl;
}