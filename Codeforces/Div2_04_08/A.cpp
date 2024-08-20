#include <bits/stdc++.h>

using namespace std;

    



int main(){

    int t;
    cin >> t;

    while(t--){
        
        int n;
        cin >> n;
        map<char,int>op;
        op['A'] = n;
        op['B'] = n;
        op['C'] = n;
        op['D'] = n;
        string s;
        cin >> s;

        int ans = 0;
        for (int i = 0; i < 4*n; i++)
        {
            if(s[i] == '?')continue;

            if(op[s[i]] == 0)continue;

            op[s[i]]--;
            ans++;
        }
        
        cout << ans <<  "\n";


    }
    return 0;

}