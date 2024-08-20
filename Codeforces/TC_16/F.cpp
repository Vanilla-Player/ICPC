#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int t;
    cin >> t;
    while(t--){

        string s;
        cin >> s;

        vector<int> pos_r;
        pos_r.push_back(0);

        //Recorro y busco las R's
        for (int i = 1; i <= s.size(); i++)
        {
            
            if(s[i - 1] == 'R'){
                pos_r.push_back(i);
            }
        }
        
        pos_r.push_back(s.size()+1);
        int ans = 0;
        // La distancia maxima de dos R sera la distancia para llegar al destino
        //Debido a que el camino es una secuencia de R
        // Las L no aportan info
        // cout << pos_r.size() << endl;
        for (int i = 0; i < pos_r.size() - 1; i++)
        {
            ans = max(ans, pos_r[i + 1] - pos_r[i]);
        }
        
        cout << ans << endl;

    }

}