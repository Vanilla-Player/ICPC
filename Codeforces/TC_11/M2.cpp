#include <bits/stdc++.h>
using namespace std;
#define  dprint(v) cout << #v"=" << v << endl //;)
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
ll n,m,k,t, D;
vector<vector<int > >gr;
vector<pair<int,int> >ans;
vector<int> visited;


void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){

        int v = q.front();
        q.pop();

        for(auto to: gr[v]){
            if(visited[to])continue;
            ans.pb(make_pair(v,to));
            visited[to] = 1;
            q.push(to);
        }

    }
}

int main(){


    cin >> n >> m;

    gr = vector<vector<int> >(n+1);
    vector<int>degrees(n+1);
    visited = vector<int>(n+2);

    forr(i,1,m+1){
        int from, to;
        cin >> from >> to;
        degrees[from]++;
        degrees[to]++;

        gr[from].pb(to);
        gr[to].pb(from);

    }

    int max_degree = 0;
    forr(i,1,n + 1){
        if(degrees[max_degree] < degrees[i]){
            max_degree = i;
        }
    }

    bfs(max_degree);
    // cout << "SOL" << endl;
    for(auto pp: ans){
        cout << pp.first << " " << pp.second << "\n";
    }

    return 0;

}