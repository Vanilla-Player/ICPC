#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;

    cin >> n >> k;

    vector<bool>dp(105,false);
    vector<int>nums;

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        if(!dp[num]){
            nums.push_back(i);
            dp[num]= true;
        }
    }
    

    int count = 0;
    for (int i = 0; i < 101; i++)
    {
        if(dp[i]){
            count++;
        }
    }
    
    if(count >= k){
        cout << "YES" << endl;
        for(int i; i < k; i++){
            cout << nums[i] << " ";
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
    }


}