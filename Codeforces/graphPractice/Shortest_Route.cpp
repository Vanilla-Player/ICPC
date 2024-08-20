#include <bits/stdc++.h>
#define ll long long
#define MAX_N 100050
using namespace std;


vector<ll> distances(MAX_N,1e15);
int cities_q, routes_q;
vector<vector<pair<ll, ll> > >adj((int)MAX_N);
vector<bool>processed((int)MAX_N,false);


int main(){

    cin >> cities_q >> routes_q;

    for (int i = 0; i < routes_q; i++)
    {
        int city, dest, weight;
        cin >> city >> dest >> weight;
        adj[city].push_back(make_pair(dest, weight));
    }

    queue<pair<ll,int> >q;
    q.push(make_pair(0,1));
    distances[1] = 0;

    while (!q.empty())
    {
        int city = q.front().second;q.pop();
        if(processed[city])continue;
        processed[city] = true;

        for (auto adjC:adj[city])
        {
            int C = adjC.first;
            ll W = adjC.second;
            if(distances[city]+W < distances[C]){
                distances[C] = distances[city]+W;
                q.push(make_pair(-distances[C],C));
            }
        }
        
    }
    
    for (int i = 1; i <= cities_q; i++)
    {
        cout << distances[i] << " ";
    }
    

    return 0;
}