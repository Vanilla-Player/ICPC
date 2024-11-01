#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define fori(i,n) for(int i = 0; i < (n);i++)
#define fora(i,a,n) for(int i = (a); i <= (n);i++)
#define MAX_N 100050
#define fill(a, v) memset(a, (long long)v, sizeof(a))
#define oper max

const int INF = 1e9 + 7;

int dp[MAX_N];

int arr[MAX_N];

int main(){

    int t;
    cin >> t;
    while(t--){
        fill(dp,0);
        fill(arr,0);

        int n;
        cin >> n;
        fori(i,n){
            cin >> arr[i];
        }

        dp[n - 1] = arr[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            dp[i] = max(dp[i+1]+1,arr[i]);
        }
        int mas = 0;
        fori(i,n){
            mas = max(dp[i], mas);
        }
        cout << mas << endl;
        

    }

}