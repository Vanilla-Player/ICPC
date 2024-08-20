#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    ll t;
    cin >> t;
    while (t--)
    {
        ll N;
        cin >> N;
        vector<ll > array;
        for (ll i = 0; i < N; i++)
        {
            ll number;
            cin >> number;
            array.push_back(number);
        } 
        
        ll count = 0;
        ll acum = 0;
        ll max = 0;
        for (ll i = 0; i < N; i++)
        {
            
            if(max <= array[i]){
                acum += max;
                max = array[i];
            }else{
                acum += array[i];
            }
                
            if(max == acum){
                count++;
            }
        }
        cout << count << endl;
        array.clear();
    }
    
        
    return 0;
}