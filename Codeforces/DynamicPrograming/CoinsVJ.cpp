#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
ld dp[3010][3010];
ld prob[3010];
ll mod = 1e9+7;


int main(){

    fast_io;

    ll n,x;
    memset(dp,0.0,sizeof(dp));
    memset(prob,0.0,sizeof(prob));

    cin>>n;
    for (ll coins = 1; coins <= n; coins++)
    {
        ld probi;
        cin >> probi;
        prob[coins] = probi;
    }


    dp[0][0] = 1.0; // ways to achieve sum of 0,using the array = 1, i.e = taking a null subset. 

    for (ll coins = 1; coins <= n; coins++)
    {
        dp[coins][0] = (1 - prob[coins]) * dp[coins - 1][0];
    }


    
    
    for(ll coins=1;coins<=n;coins++)//we take each coin specifically, and do the needed calculations
    {
        for (ll heads = 1; heads <= coins; heads++)
        {
            dp[coins][heads] = ((1 - prob[coins])* dp[coins - 1][heads]) + (prob[coins]*dp[coins-1][heads-1]);   
        }
        
    }
// IF You want to print the dp matrix
    // for (ll i = 0; i <= n; i++)
    // {
    // for (int j = 0; j <= n; j++)
    //     {
    //        cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ld ans = 0;
    for (int i = (n+1)/2; i <= n; i++)
    {
        ans += dp[n][i];
    }// This works because:
    // for case 2 with n = 1 => i = 1
    // for case 1 with n = 3 => i = 2
    // for case 3 with n = 5 => i = 3
    //Then you can try (n+1)/2
    
    cout<< setprecision(9) << ans <<endl;
    return 0;
}