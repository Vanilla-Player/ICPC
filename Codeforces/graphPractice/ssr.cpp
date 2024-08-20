#include <bits/stdc++.h>

#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 9e18;

int adj[502][502];
ll distancia[502][502];
queue<pair<int,int>> qs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,q;
    cin >> n >> m >> q;
    forn(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        if (adj[a][b] == 0) {
            adj[a][b] = c;
            adj[b][a] = c;
        }
        else if (c < adj[a][b]) {
            adj[a][b] = c;
            adj[b][a] = c;
        }
    }
    forn(i,q) {
        int a,b;
        cin >> a >> b;
        qs.push({a,b});
    }
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            if (i == j) distancia[i][j] = 0;
            else if (adj[i][j] != 0) distancia[i][j] = adj[i][j];
            else distancia[i][j] = INF;
        }
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n;j++) {
                if (distancia[i][k] != INF && distancia[k][j] != INF) {
                    distancia[i][j] = min(distancia[i][j], distancia[i][k] + distancia[k][j]);
                }
            }
        }
    }
    while(!qs.empty()) {
        pair<int,int> x = qs.front();
        qs.pop();
        if (distancia[x.fst][x.snd] == INF) cout << -1 << '\n';
        else cout << distancia[x.fst][x.snd] << '\n';
    }
}