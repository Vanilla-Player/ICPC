#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<int> vi;

#define fori(i,n) for(int i = 0; i< (n); i++)
#define fora(i,a,n) for(int i = a; i<= (n); i++)

#define fi first
#define se second
#define pb push_back

#define dprint(v) cout << #v"=" << v << endl //;)

const int MAX_N = 10000;

int ids[MAX_N];
vector<vector<int> > adj(MAX_N);
vector<int> top_list;
bool not_pos = false;

void dfs(int node){

    for(auto v: adj[node]){
        if(ids[v] == 2){
            continue;
        }
        if(ids[v] == 1){
            not_pos = true;
        }
        if(ids[v] == 0){
            ids[v] = 1;
            dfs(v);
            if(not_pos) return;
        }
    }
    ids[node] = 2; // Mark the node as fully processed
    top_list.pb(node); // Add node to the topological sort list 
   
}

int main(){

    int n, c;

    cin >> n >> c;

    fori(i,c){
        int s,e;
        cin >> s >> e;
        adj[s].pb(e);
    }
// 6 7 // (nodes) (verices)
// 4 5
// 4 1
// 5 2
// 2 3
// 1 2
// 3 6
// 5 3
    fora(i,1, n){
        if(ids[i] == 0){
            ids[i] = 1;
            dfs(i);
        }
        if(not_pos){
            cout<< "NOT POSSIBLE" << endl;
            return 0;
        }
    }

// Cout topological

for (int i = top_list.size() - 1; i >= 0; i--)
{
    cout << top_list[i] << " ";
}

}