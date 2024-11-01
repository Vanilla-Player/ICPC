#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        string s1,s2;
        cin >> s1 >> s2;

        string ns1 = "", ns2 = "";
        int b1 = 0, b2 = 0;
        for(char x: s1){

            if(x == 'B' ){ //&& ns1[ns1.size() - 1] == 'B'
                b1+=1;
                // ns1.pop_back();
            }else if(ns1.size() == 0 || ns1[ns1.size() - 1] != x){
                ns1 += x;
            }else{
                ns1.pop_back();
            }
        }

        for(char x: s2){

            if(x == 'B'){  // && ns2[ns2.size() - 1] == 'B'
                b2+=1;
                // ns2.pop_back();
            }else if(ns2.size() == 0 || ns2[ns2.size() - 1] != x){
                ns2 += x;
            }else{
                ns2.pop_back();
            }
        }

        if(ns1 == ns2 && b1 % 2 == b2 % 2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }


}