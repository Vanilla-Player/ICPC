#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
const int MAXN=100100;
ll n,m,t;

int dx[4] = {1,0,-1,0}; 
int dy[4] = {0,1,0,-1};
string fl[2] = {"^<v>","v>^<"};

int main(){

    cin >> n >> m;
    vector<string> matrix;
    forn(i,n){
        string row;
        cin >> row;
        matrix.pb(row);
    }
    vector<vector<int> >deg(m>n?m:n,vector<int>(m>n?m:n,0));
    queue<ii> nodes; //  Queue para tener los nodos de Grado 1;
    forn(i,n){
        forn(j,m){
            forn(k,4){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < n && nx >= 0 && ny < m && ny >= 0){
                    if(matrix[nx][ny] == '.'){
                        deg[i][j]++;
                    }
                }
            }
            if(matrix[i][j] == '.'){

                if(deg[i][j] == 1){nodes.push(make_pair(i,j));}// push to the queue
            }
        }
    }



    while(!nodes.empty()){

        ii node = nodes.front();
        nodes.pop();
        int x = node.fst;
        int y = node.snd;
        if(matrix[x][y] == '.'){
            int nx,ny;
            int id = -1;
            bool succ = false;
            forn(k,4){
                nx = x + dx[k];
                ny = y + dy[k];
                id = k;
                if(nx < n && nx >= 0 && ny < m && ny >= 0){
                    if(matrix[nx][ny] == '.'){
                        succ=true;
                        break;
                    }
                }
            }
            if(!succ){
                cout << "Not unique" << endl;
                return 0;
            }
            matrix[x][y] = fl[0][id];
            matrix[nx][ny] = fl[1][id];
            deg[x][y] = 0;
            deg[nx][ny] = 0;


            forn(k,4){
                int nnx = nx + dx[k];
                int nny = ny + dy[k];
                if(nnx < n && nnx >= 0 && nny < m && nny >= 0){
                    
                    deg[nnx][nny]--;
                    if(deg[nnx][nny] == 1){
                        nodes.push(make_pair(nnx,nny));
                    }
                }
            }
 
        }

        
    }

    
    forn(i,n){
        forn(j,m){
            if(matrix[i][j] == '.'){
                cout << "Not unique" << endl;
                return 0;
            }
        }
    }

    forn(i,n){
        forn(j,m){
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;

}