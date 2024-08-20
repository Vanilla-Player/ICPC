
#include <bits/stdc++.h>


using namespace std;

const int MAX_N = 10e5;
vector<vector<int>> dp(MAX_N+1, vector<int>(MAX_N+1, 0));

int solve(int x,int y, vector<int> h){
    if(x == y){
        return h[x];
    }
    if(x > y){
        return INFINITY;
    }
    if(dp[x][y]){
        return dp[x][y];
    }
    

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);


    int stonesNumber;
    int m = 10e5;

    
    vector<int> h;

    cin >> stonesNumber;



    for(int i = 0; i < stonesNumber; i++){
        int height;
        cin >> height;
        h.push_back(height);
    }

    int result = solve(0, stonesNumber - 1, h);

}

