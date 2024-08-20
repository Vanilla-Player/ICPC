#include <bits/stdc++.h>

using namespace std;





int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        long long n;



        cin >> n;
        int acum = 0;
        vector<int> nums;
        bool hasValue = false;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            int num3 = num%3;
            acum += num3;
            if(num3 == 1){
                hasValue = true;
            }
        }

        int rest = acum%3;

        // cout << "rest" << endl;
        // cout << rest << endl;
        
        if(rest == 0){
            cout << "0" << endl;
        }else if(rest == 2){
            cout << "1" << endl;
        }else{
            if(hasValue){
                cout << "1" << endl; // If i have to eliminate it
            }else{
                cout << "2" << endl; // If I have to increase plus 
            }
        }
    }

}