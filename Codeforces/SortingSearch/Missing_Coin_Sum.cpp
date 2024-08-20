
#include <bits/stdc++.h>
#define lli long long 




using namespace std;

lli N, totalProducts, maxVal = 0;
vector<lli> coins;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N ;

    for (lli i = 0; i < N; i++)
    {
        lli coin;
        cin >> coin;
        coins.push_back(coin);
    }

    sort(coins.begin(),coins.end());
    long long ans = 1;
    for(int c: coins ) {
        if(c > ans) break;
        ans += c;
    }

    cout << ans << endl;

    return 0;

}

