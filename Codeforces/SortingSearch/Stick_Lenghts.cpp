
#include <bits/stdc++.h>
#define ll long long 




using namespace std;

ll N, totalProducts, maxVal = 0;
vector<ll> v;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N ;

    for (ll i = 0; i < N; i++)
    {
        ll number;
        cin >> number;
        v.push_back(number);
    }

    sort(v.begin(),v.end());
    ll middle = v[N / 2];
    ll l = 0;
    ll r = N - 1;
    ll cost = 0;
    while(l<r){
        cost+= middle - v[l];
        cost+= v[r] - middle;
        l++;
        r--;
    }

    cout << cost << endl;

    return 0;

}

