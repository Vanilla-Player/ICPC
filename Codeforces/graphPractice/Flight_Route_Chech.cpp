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

vector<int> adj[MAXN];
int ids[MAXN];
int low[MAXN];

vector<vector<int> >comps(MAXN);
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
        // cout << "createComp\n"; 
        // cout << "before\n" ;
        // dprint(node);
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
    
    // Seed the random number generator
    srand(time(0));
    int n,m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        ids[i] = -1;
        low[i] = -1;
    }

    fori(i,m){
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        conexion[mp(from,to)]++;
    }

    fori(i,n){
        if(ids[i + 1] == -1){
            tarjan(i + 1);
        }
    }

    int cont = 0;
    fora(i,1,n){
        if(comps[i].size() != 0){
            cont++;
        }
        
    }

    if(cont < 2){
        cout << "YES" << "\n";
        return 0; 
    }
    cont = 0;
    cout << "NO" << "\n";
    int first = 0;
    ford(i,n,1){
        if(comps[i].size() != 0 && cont < 2){
            
                cout << comps[i][(rand() % comps[i].size())] << " ";
            
            cont ++;
        }
        if(cont == 2){
            break;
        }
    }
    // cout << "\n";
    // ford(i,1,n){
    //     dprint(comps[i].size());
    //     if(comps[i].size() == 0)continue;
    //     fori(j,comps[i].size()){
    //         cout << comps[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}