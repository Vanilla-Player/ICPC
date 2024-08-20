
#include <bits/stdc++.h> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 


string s;
long long n;


int main()
{
    fast_io;


    cin >> n;
    int number;
    cin >> s;


    int ans = 0;

    int l = 0;
    int r = n;


    for (int l = 0; l < n ; l++)
    {
        int left = s[l] - '0';
        if(left%2 == 0){
            ans+= l+1;
        }
        // for (int r = 0; r < n ; r++)
        // {
        //     if(l == r) continue;
        //     int result;
        //     int right = s[r] - '0';
        //     if(left > right){
        //         result = right*10 + left;
        //     }else{
        //         result = left*10 + right;
        //     }
        //     if(((result)% 2 == 0)){
        //         dp[l][r] = true;
        //         ans++;
        //     }
        // }
    }
    
    cout << ans << endl;
    

   return 0;
}