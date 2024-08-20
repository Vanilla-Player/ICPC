#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll dp[(ll)200001];
vector<int> attack;
vector<int> cooldown;
ll h,n;

bool solve(ll turns){

    int to = 0;
    int damage = 0;

    while(h >= damage){

        for (int i = 0; i < n; i++)
        {
            if(to==0){
                damage+=attack[i];
                dp[i] = cooldown[i];
                continue;
            }
            if(dp[i] <= to){
                damage+=attack[i];
                dp[i] = cooldown[i] + to;
            }
        }
        to++;
    }
    cout << "turns" << endl;
    cout << to << endl;

    return to < turns;
}

int main(){
    ll t;
    cin >> t;
    while (t--)
    {

        memset(dp,0,200001);
        ll l = 1;
        ll r = 200001;
        cin >> h >> n;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            attack.push_back(a);
            
        }
        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            cooldown.push_back(c);
            
        }
        
        int damage = 0;
        int to = 0;

        while(h >= damage){

        for (int i = 0; i < n; i++)
        {
            if(to==0){
                damage+=attack[i];
                dp[i] = cooldown[i];
                continue;
            }
            if(dp[i] <= to){
                damage+=attack[i];
                dp[i] = cooldown[i] + to;
            }
        }
        to++;
    }
    cout << "Solution" << endl;
    cout << to << endl;

        
    }
    
        
    return 0;
}