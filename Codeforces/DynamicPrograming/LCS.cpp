#include <bits/stdc++.h>
#define ll long long 
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int dp[3010][3010];

int main(){

    fast_io;

    memset(dp,0,sizeof(dp));
    string s,t;
    cin >> s;
    cin >> t;

    int len_s = s.length();
    int len_t = t.length();
    char sol[len_s > len_t?len_t:len_s][len_s > len_t?len_t:len_s];


    for (int sub_s = 1; sub_s <= len_s; sub_s++)
    {
        for (int sub_t = 1; sub_t <= len_t; sub_t++)
        {
            if(s[sub_s - 1] == t[sub_t - 1]){
                dp[sub_s][sub_t] += dp[sub_s - 1][sub_t - 1] + 1;

            }else{
                dp[sub_s][sub_t] += max(dp[sub_s - 1][sub_t], dp[sub_s][sub_t - 1]);
            }
        }
        
    }
    
    string ans = "";
    while (len_s > 0 && len_t > 0)
    {
        if(s[len_s - 1] == t[len_t - 1]){

            ans = s[len_s - 1] + ans;
            len_s --;
            len_t --;
        }else{
            if(dp[len_s][len_t - 1] >= dp[len_s - 1][len_t]){
                len_t--;
            }else{
                len_s--;
            }

        }
    }
    

    cout << ans << endl;

    return 0;
}