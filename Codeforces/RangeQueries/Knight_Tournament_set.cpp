
#include <bits/stdc++.h>

using namespace std;

int n,m;

set<int> fighters;
vector<int>res(300001,0);


int main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        fighters.insert(i);
    } 
    while(m--){
        int l,r,w;

        cin >> l >> r >> w;

        auto it = fighters.lower_bound(l);

        while(it != fighters.end() && *it <=r){
            
            auto it2 = it;
            it++;
            if(*it2 != w){

                res[*it2 - 1] = w;
                fighters.erase(it2);
            }
            
        }

    }
    
    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    cout << "\n";
}