
#include <bits/stdc++.h> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 

#define MAX_N 100005
#define ll long long

vector<pair<ll,ll> > info(10);

int N;
vector<vector<ll> > distances(10, vector<ll>(10,1e10));


void dfs(int node,int h){

    if(h == N ) {

        ll c,a,a2;
        tie(a,c) = info[node];
        a2 = info[1].first;
        ll dist = max(c,a2 - a) + distances[h - 1][node];

        cout << "increase" << endl;
        cout << distances[h - 1][node] << endl;
        cout << "LAST SUM" << endl;
        cout << dist << endl;

        distances[h][1] = min(dist,distances[h][1]);

        return;
    }

    for (int n = 2; n <= N; n++)
    {
        if(n == node)continue;

        ll c,a,a2;
        tie(a,c) = info[node];
        a2 = info[n].first;
        ll dist = max(c,a2 - a) + distances[h - 1][node];
        cout << "FROM " << node << endl;
        cout << "TO " << n << endl;
        cout << "DIST " << dist << endl;


        distances[h][n] = min(dist,distances[h][n]);
        dfs(n,h+1);
    }

}


int main()
{
    fast_io;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        distances[0][i] = 0;
    }
    
    for(int i = 1;  i<= N; i++){
        ll beauty,cost;
        cin >> beauty >> cost;
        info[i] = make_pair(beauty, cost);    
    }

    dfs(1,1);

    // for (int i = 1; i <= N; i++)
    // {
    //     cout << distances[N + 1][i];
    //    cout << endl;
    // }
    

    cout << distances[N ][1] << endl;

    return 0;
}