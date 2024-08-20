#include <bits/stdc++.h>
#define ll long long 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int N;
int v[100];
int dp[(int)1e6+10];
int mod = 1e9 + 7;

int main(){

    fast_io;
    int X;
    cin >> N >> X;

    for (int i = 0; i < N; i++)
    {
        int numb;
        cin >> numb ; v[i] = numb;
    }
    

    dp[0] = 1;
    for (int x = 1; x <= X; x++)
    {
        for (int i = 0; i < N ; i++)
        {
            if(x-v[i] >= 0){
                dp[x] += dp[x-v[i]];
                dp[x] %= mod;
            }
        }
        
    }
    
    cout << dp[X] << endl;
    return 0;
}