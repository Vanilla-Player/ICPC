#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){

    int  t;


    cin >> t;

    while(t--){
        
        int count[3];
        count[0] = 0;
        count[1] = 0;
        count[2] = 0;
        
        for (int i = 0; i < 3; i++)
        {
            string row;
            cin >> row;
            for (int j = 0; j < 3; j++)
            {

                if(row[j]== 'A'){
                    count[0]++;
                }else if(row[j] == 'B'){
                    count[1]++;
                }else if(row[j] == 'C'){
                    count[2]++;
                }
            }

        }

        if(count[0] != 3){
            cout << "A" << endl;
        }
        if(count[1] != 3){
            cout << "B" << endl;
        }
        
        if(count[2] != 3){
            cout << "C" << endl;
        }
        
    }

    return 0;
}