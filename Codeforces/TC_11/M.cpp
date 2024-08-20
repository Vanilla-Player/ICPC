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



vector<int> color;
vector<int> p;
ll cnt = 0;
vector<pair<int, int>> ans;
vector<vector<int> >gr;

// TO DO


void bfs(int s, int bad) {
	queue<int> q;
	q.push(s);
	color[s] = cnt;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (p[v] != -1) {

			if (rnd() & 1) ans.push_back(make_pair(p[v], v));
			else ans.push_back(make_pair(v, p[v]));
		}
		for (auto to : gr[v]) {
			if (to == bad || color[to] != -1) continue;
			p[to] = v;
			color[to] = cnt;
			q.push(to);
		}
	}
	++cnt;
}


int main(){

    // Load the grap
    cin >> n >> m >> D;
    
    gr = vector<vector<int> >(n);
    forn(i,m){
        int from, to;

        cin >> from >> to;

        --from;--to;
        gr[from].pb(to);
        gr[to].pb(from);
    }


    p = color = vector<int>(n, -1);
    cnt = 0;

    forn(i,n){
        if(color[i] == -1){
            bfs(i,0);
        }

    }

    if(cnt > D || D > int(gr[0].size())){
        cout << "NO" << endl;
        return 0;
    }

    sort(gr[0].begin(), gr[0].end(), [](int a, int b) {
		return color[a] < color[b];
	});

    forn(i,int(gr[0].size())){
        
        if(i == 0 || color[gr[0][i]] != color[gr[0][i-1]] ){

            ans.pb(make_pair(0,gr[0][i]));
        }

    }
    D -= cnt;

    forr(i,1, int(gr[0].size())){
        if(D == 0)break;
        if(color[gr[0][i]] == color[gr[0][i - 1]]){
            ans.pb(make_pair(0,gr[0][i]));
            D--;
        }
    }

    gr = vector<vector<int> >(n);

    for(auto pa: ans){

        gr[pa.first].push_back(pa.second);
		gr[pa.second].push_back(pa.first);

    }
  
    ans.clear();

    p = color = vector<int>(n,-1);

    cnt = 0;

    bfs(0,-1);

    shuffle(ans.begin(), ans.end(), rnd);
    cout << "YES" << endl;
	for (auto it : ans) {
		cout << it.first + 1 << " " << it.second + 1 << endl;
	}
    return 0;
}