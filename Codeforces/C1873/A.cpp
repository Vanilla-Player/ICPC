
#include <bits/stdc++.h>


using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){

        string cards;
        string order = "abc";

        cin >> cards;

        int dif = 0;
        for (int j = 0; j < order.length(); j++)
        {
            if(cards[j] != order[j]){
                dif++;
            }

        }
        
        if (dif > 2)
        {
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << "\n";

    }

}