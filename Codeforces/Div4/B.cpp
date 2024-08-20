#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){

    int N;
    int t;

    cin >> t;
    while (t--)  
    {
        cin >> N;

        int maximum = 0;
        int indexMax = 0;
        for (int i = 2; i <= N; i++)
        {
            int acum = 0;
            for (int j = 1; j < N; j++)
            {
                int value = i*j;
                if(value <= N){
                    acum +=value;
                }
            }
            if(acum > maximum){
                indexMax = i;
                maximum = acum;
            }
        }
        
        cout << indexMax << endl;
    }
    
    



    return 0;
}