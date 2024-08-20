
#include <bits/stdc++.h> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 

int main()
{
    fast_io;

    int books, money;
    cin>>books >> money; //taking input
    vector<int> prices(books);
    for(int&i : prices)
    cin>>i;
    vector<int> pages(books);
    for(int&i : pages)
    cin>>i;

    vector<vector<int> > dp(books+1,vector<int>(money+1,0));
    
    for(int i=1;i <= books;i++) 
    {   
        
        for(int j = 0; j < money; j++) 
        {
            dp[i][j] = dp[i-1][j];
            if(j>=prices[i-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-prices[i-1]] + pages[i-1]);
            }
        }
    } 

    cout<<dp[books][money]<<endl;
    return 0;
}