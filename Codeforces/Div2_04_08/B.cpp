#include <bits/stdc++.h>

using namespace std;

#define ll long long

    

ll query(ll a, ll b){



}



int main(){

    ll t;
    cin >> t;

    while(t--){
        
        ll n;
        cin >> n;

        ll even = 0;
        ll odd= 0;
        ll maxOdd = 0;
        vector<ll> evens;
        for (ll i = 0; i < n; i++)
        {
            ll num;
            cin >> num;
            if((num & 1) == 0){
                even++;
                evens.push(even);
            }else{
                odd = max(odd, num);
            }
        }
        if(!odd || !even){
            cout << "0" << "\n";
            continue;
        }



        sort(evens.begin(),evens.end());

        vector<int> acumsEven(sizeof(evens))

        for (int i = 0; i < sizeof(evens); i++)
        {
            int num = evens[i];
            int acumsEven[i] = num + acumsEven[i-1]
        }
        
        
        ll l = 0;
        ll r = sizeof(evens);
        ll flag = 0;
        while(l<r){
            ll mid = (l+r)/2;

            if((acumsEven[mid] + ))
        }
        ll ans = even;



    }
    return 0;

}