#include <bits/stdc++.h>
#include <cstdio>


using namespace std;
int qMoves, qStones;
int A[101];
int dp[(int)1e5+1];

int win(int stones){
    if (dp[stones] != -1){
        return dp[stones];
    } 
    bool result = false;
    for (int i = 0; i < qMoves; i++)
    {
        if(stones - A[i] >= 0){
            int g = win(stones);
            result = result || !g;
        }
    }
    dp[stones] = result;
    return dp[stones];
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);


    
    int m = 10e5;

    
    vector<int> h;

    cin >> qMoves >> qStones;
    for (int i = 0; i <= qStones; i++){
        dp[i] = -1;
    }

    for (int i = 0; i < qMoves; i++)
    {
        cin >> A[i];
    }
    

    bool winner = win(qStones);

    if(winner){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }

    return 1;
}
