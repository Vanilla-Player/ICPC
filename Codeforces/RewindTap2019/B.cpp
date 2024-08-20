#include <bits/stdc++.h>
#define ll long long 
#define llf long long float 

using namespace std;

int main(){


    ll N;
    vector<pair<ll, ll> > banks;
    vector<ll> banks_radius; 

    cin >> N;

    for(ll i = 0; i < N; i++){
        ll x,y,r;
        cin >> x >> y >> r;
        banks.push_back(make_pair(x,y));
        banks_radius.push_back(r);
    }

    bool works = true;
    for (ll bank1 = 0; bank1 < N; bank1++)
    {
        pair<ll, ll> pair1 = banks[bank1];
        ll x1 = pair1.first;
        ll y1 = pair1.second;
        ll r1 = banks_radius[bank1];
        for (ll bank2 = 0; bank2 < N; bank2++)
        {
            if(bank1 == bank2)continue;
            pair<ll, ll> pair2 = banks[bank2];
            ll x2 = pair2.first;
            ll y2 = pair2.second;
            ll r2 = banks_radius[bank2];
            // cout << "BANK1" << endl;
            // cout << x1 << " " << y1 << endl;
            // cout << "BANK2" << endl;
            // cout << x2 << " " << y2 << endl;
            float d = sqrt(pow(x2-x1,2) + pow(y1 - y2,2));
            // cout << "Distance" << endl;
            // cout << d << endl;
            if(d <= (r1 + r2)){
                ll biggest;
                ll smallest;

                if(r1<r2){
                    smallest = r1;
                    biggest = r2;
                }else{
                    smallest = r2;
                    biggest = r1;
                }
                if(d + smallest < biggest){
                    continue;
                }

                cout << "NO" << endl;
                works = false;
                break;
            }
        }
        if(!works){
            break;
        }
    }
    
    if(works){
        cout << "SI" << endl;
    }

    return 0;
}