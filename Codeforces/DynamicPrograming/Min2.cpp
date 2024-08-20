#include <bits/stdc++.h>


using namespace std;

int N, C;

int value[(int)1e6];
int mod = 1e9 + 7;

int main(){
        cin >> N >> C;

    vector<int > coins;

    for (int i = 0; i < N; i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    bool sol = false;
    value[0] = 0;
    for (int x = 1; x <= C; x++) {
        value[x] = 1e6+1;
        for (int it=0;it < N;it++) {
            int coin = coins[it];
           if (x-coin >= 0) {
                sol = true;
               value[x] = min(value[x], value[x-coin]+1);
                
            } 
        }

    }
    
    if(value[C] == 1e6+1){
        cout << "-1" << endl;
    }else{
    cout << value[C] << endl;
    } 
    return 0;
}