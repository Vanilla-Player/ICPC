#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
bool dp[(int)1e5+10];
int stones[105];


int main(){

    fast_io;
    int n,k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
    }
    dp[0] = false;
    for (int stones_q = 1; stones_q <= k; stones_q++)
    {
        dp[stones_q] = false;
        for (int remove = 0;  remove< n; remove++)
        {
            int stones_r = stones[remove];

            if( stones_q - stones_r >= 0 && !dp[stones_q-stones_r]){
                dp[stones_q] = true;
            }
        }
        
    }
    
    if(dp[k]){
        cout << "First " << endl;
    }else{
        cout << "Second " << endl;
    }
    
    return 0;
}