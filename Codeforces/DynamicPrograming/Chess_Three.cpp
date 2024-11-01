#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define fori(i,n) for(int i = 0; i < (n);i++)
#define fora(i,a,n) for(int i = (a); i <= (n);i++)
#define MAX_N 32
#define fill(a, v) memset(a, (long long)v, sizeof(a))
#define oper max

const int INF = 1e9 + 7;

int dp[MAX_N][MAX_N][MAX_N];
int visited [MAX_N] [MAX_N] [MAX_N];
int t, p1,p2,p3;



int solve(int x1, int x2, int x3){

    if(visited[x1][x2][x3])return dp[x1][x2][x3];
    visited[x1][x2][x3] = 1;

    int ans = 0;
    if(x1 >= 2) ans = max(ans,solve(x1-2,x2,x3));
    if(x2 >= 2) ans = max(ans,solve(x1,x2-2,x3));
    if(x3 >= 2) ans = max(ans,solve(x1,x2,x3-2));
    if(x1 >= 1 && x2 >=1) ans = max(ans,solve(x1-1,x2-1,x3)+1);
    if(x1 >= 1 && x3 >= 1) ans = max(ans,solve(x1-1,x2,x3-1)+1);
    if(x2 >= 1 && x3 >=1) ans = max(ans,solve(x1,x2-1,x3-1)+1);

    dp[x1][x2][x3] = ans;
    return ans;

}

int main(){

    cin >> t;
    while(t--){

        
        cin >> p1 >> p2 >> p3;
        if((p1+p2+p3)%2 != 0){
            cout << "-1" << endl;
            continue;
        }
        fill(dp,0);
        fill(visited,0);

        cout << solve(p1,p2,p3) << endl;


    }


}