
#include <bits/stdc++.h>

using namespace std;

#define ll long long

long long n,m,k,t;



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--){

        cin >> n;

        vector<char>start;
        vector<char>end;
        string s;
        cin >> s;

        string sol = "";
        char ant = s[0];
        int k = 1;
        start.push_back(ant);

        for(int i = 1; i < n ; i++){

            char curr = s[i];

            if(ant > curr){
                k++;
                ant = curr;
                start.push_back(curr);
            }else{
                break;
            }

        }

        for (int i = 0; i < k; i++)
        {
            sol+=start[i];
        }
        
        for (int i = k - 1; i >= 0; i--)
        {
            sol+=start[i];
        }
        
        // cout << "SOL" << endl;
        cout << sol << endl;

    }

}