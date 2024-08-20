#include <bits/stdc++.h>

using namespace std;
#define ll long long



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
         ll n,k;

        cin >> n >> k;

        ll cur = 1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            cur *= 1LL*x;
        }
        

        if(2023 % cur){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        cout << 2023/cur << " ";

        for (int i = 0; i < k-1; i++)
        {
            cout << "1" << " ";
        }
        cout << endl;
    }

}