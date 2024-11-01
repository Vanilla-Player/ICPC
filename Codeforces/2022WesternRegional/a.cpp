#include <bits/stdc++.h>

using namespace std;

int main(){


    int t;
    cin >> t;

    while(t--){

        set<int>difficulties;
        vector<int>dif_beauty(11,0);
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int beauty, dif;
            cin >> beauty >> dif;
            difficulties.insert(dif);
            dif_beauty[dif] = max(dif_beauty[dif], beauty);

        }

        int difs = 0;
        for (int i = 1; i <= 10; i++)
        {
            difs += difficulties.count(i);
        }

        if(difs < 10){
            cout << "MOREPROBLEMS" << endl;
        
        }else{
            int sum = 0;
            for (int i = 1; i <= 10; i++)
            {
                sum += dif_beauty[i];
            }
            
            cout << sum << endl;
        }
        


    }

}