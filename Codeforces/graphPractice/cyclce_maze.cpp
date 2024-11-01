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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1010;


ll n,m,k;

vector<int>moveX = {1, 0,0,-1};
vector<int>moveY = {0, -1,1,0};
queue<ii> q;

 
int d[MAXN][MAXN];
 
char c[MAXN][MAXN];

bool can_move(int x, int y){
    return (x >= 1 && y >= 1 && x <=n && y <= m && c[x][y]!= '*'); 
}

void bfs(int x, int y){
   fill(d, -1);
   d[x][y] = 0;
    q.push(mp(x,y));
    while(!q.empty()){
        ii pos = q.front();
        x = pos.fi;
        y = pos.se;
        q.pop();
        fori(dir, 4){
            int nx = moveX[dir];
            int ny = moveY[dir];
            if(can_move(x + nx, y+ny) && d[x+nx][y+ny] == -1){
                d[x+nx][y+ny] = d[x][y] +1;
                q.push(mp(x+nx, y+ny));
            }
        }
    }
}

void solve(){
    
    cin >> n >> m >> k;
    
    int xs,ys;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= m; j++){
            cin >> c[i][j];
            if(c[i][j]== 'X'){
                xs = i;
                ys = j;
            }
        }
    }

    if(k % 2 == 1){
        cout << "IMPOSSIBLE" << "\n";
        return;
    }
    bfs(xs,ys);

    vector<char>movs = {'D','L','R','U'};

    int x = xs;
    int y = ys;
    bool had_move = 0;
    string ans = "";
    for (int i = 1; i <= k; i++)
    {
        had_move = 0;
        fori(dir,4){
            int nx = moveX[dir];
            int ny = moveY[dir];
            if(can_move(x + nx,y+ ny) && d[x +nx][y+ ny] != -1 && d[x +nx][y+ ny] <= k - i){
                ans += movs[dir];
                x += nx;
                y += ny;
                had_move = 1;
                break;
            }
        }
        if(!had_move){
            cout << "IMPOSSIBLE" << "\n";
            return;
        }
    }
    
    cout << ans << endl;
    return;
}


int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    
        solve();
    

    return 0;

}