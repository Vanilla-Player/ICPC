#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){

    int  t;


    cin >> t;

    while(t--){

        int N;
        cin >> N;

        int dp[N];
        memset(dp,0,N);
        string word;
        cin >> word;
        int vowels = 0;
        int consonants = 0;
        vector<string > w(N,"");

        for (int i = 0; i < N; i++)
        {
            w.push_back("");
        }
        

        for (int i = 0; i < N; i++)
        {
            if(word[i] == 'a' || word[i] == 'e'){
                // w[i] += word[i] ;
                vowels++;
            }
            // else{
            //     w[i] += word[i] ;
            //     consonants++;
            // }
        }
        
        for (int i = 0; i < vowels; i++)
        {
            for (int j = 0; j < N; j++)
            {
                
            }
            
        }
        


        
    }

    return 0;
}