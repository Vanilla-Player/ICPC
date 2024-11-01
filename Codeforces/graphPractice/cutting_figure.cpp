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
const int MAXN = 55;
vector<int>dx = {1,0,-1,0};
vector<int>dy = {0,1,0,-1};


map<ii,int> low;
map<ii,int> ids; // => {x,y} = id
map<ii,int> visited;
int art_points = 0;
int n,m;
vector<string> Graph;
int id = 0;

bool isPossilbe(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < m && Graph[x][y] == '#');
}

void dfs(ii n, int p_id){
    id++;
    low[n] = ids[n] = id;

    int childs = 0;
    fori(i,4){
        int nx = n.fi + dx[i];
        int ny = n.se + dy[i];
        if(!isPossilbe(nx,ny))continue;
        ii np = mp(nx,ny);
        if(ids[np] == p_id)continue;
        if(ids[np] != 0){
            low[n] = min(low[n],ids[np]);
        }else{
            dfs(np,ids[n]);
            low[n] = min(low[n],low[np]);
            if(low[np] >= ids[n] && p_id != -1){
                art_points++;
            }
            childs++;
        }
        
    }

    if(childs > 1 && p_id == -1){
        art_points++;
    }
    return;
}

int countedSharps = 0;


int main(){

    cin >> n >> m;
    fori(i,n){
        string row;
        cin >> row;
        Graph.pb(row);
    }
    fori(i,n){
        fori(j,m){
            if(Graph[i][j] == '#'){
                countedSharps++;
            }
        }
    }

    // dprint(countedSharps);
    if(countedSharps <= 2){
        cout << -1 << "\n";
        return 0;
    }

    fori(i,n){
        fori(j,m){
            if(Graph[i][j] == '#'){
                dfs(mp(i,j),-1);
                break;
            }
        }
    }

    if(art_points == 0){
        cout << 2 << endl;
        return 0;
    }
    cout << 1 << endl;
    
return 0;
}