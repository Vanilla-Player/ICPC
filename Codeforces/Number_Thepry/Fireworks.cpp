#include <bits/stdc++.h>

using namespace std;



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        long long a,b,m;

        cin >> a >> b >> m;

        long long res = 1LL*((m/a)+(m/b)+2);

        cout << res << endl;
    }

}