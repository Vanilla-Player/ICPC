#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int N;
int dice[6];
int dp[(int)1e6+10];
int mod = 1e9 + 7;

int main(){

    for (int i = 1; i <= 6; i++)
    {
        dice[i-1] = i;
    }
    
    cin >> N;

    dp[0] = 1;
    for (int x = 1; x <= N; x++)
    {
        for (auto d: dice)
        {
            if(x-d >= 0){
                dp[x] += dp[x-d];
                dp[x] %= mod;
            }
        }
        
    }
    
    cout << dp[N] << endl;
    return 0;
}