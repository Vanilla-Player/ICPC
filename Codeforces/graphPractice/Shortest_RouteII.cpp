#include <bits/stdc++.h>
#define ll long long
#define MAX_N 505
using namespace std;



int cities_q, routes_q, queries;
vector<vector<pair<ll, ll> > >adj((int)MAX_N);
vector<pair<int, int> > queriesList;


int main(){

    cin >> cities_q >> routes_q >> queries;

    for (int i = 0; i < routes_q; i++)
    {
        int city, dest, weight;
        cin >> city >> dest >> weight;
        adj[city].push_back(make_pair(dest, weight));
        adj[dest].push_back(make_pair(city, weight));
    }

    ll distances[queries][cities_q];
    bool processed[queries][cities_q];
    memset(processed,false,sizeof(processed));
    memset(distances,10,sizeof(distances));

    for (int i = 0; i < queries; i++)
    {
        int city, dest;
        cin >> city >> dest;
        queriesList.push_back(make_pair(city, dest));
    }

    priority_queue<pair<ll,int> >q;
    int cont = 0;
    while (queries--)
    {
        int ini = queriesList[cont].first, dest = queriesList[cont].second;
        q.push(make_pair(0,ini));
        distances[cont][ini] = 0; 

        while (!q.empty())
        {
            int city = q.top().second;q.pop();
            if(processed[cont][city])continue;
            processed[cont][city] = true;

            for (auto adjC:adj[city])
            {
                int C = adjC.first;
                ll W = adjC.second;
                if(distances[cont][city]+W < distances[cont][C]){
                    distances[cont][C] = distances[cont][city]+W;
                    q.push(make_pair(-distances[cont][C],C));
                }
            }
            
        }

        // for (int i = 1; i <= cities_q; i++)
        // {
        //     cout << distances[cont][i] << endl;;            
        // }
        
        
        if(distances[cont][dest] < 1e15){
            //cout << "OUTPUT" << endl;
            cout << distances[cont][dest] << endl;
        }else{
            
            cout << -1 << endl;
        }
        cont++;
    }
    
    

    return 0;
}