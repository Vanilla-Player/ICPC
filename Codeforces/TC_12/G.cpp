
#include <bits/stdc++.h> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 
#define ll long long
#define MAX_N 200050
string s;
long long n;
vector<bool > dp(MAX_N,false);


int main()
{
    fast_io;

    ll p;
    cin >> p;

    vector<ll> paint(11,0);
    for (ll i = 1; i <= 9; i++)
    {
        ll l;
        cin >> l;
        cout << "values" << endl;
        cout << l << endl;
        paint[i] = l;
    }

    ll maxV = 0;
    ll maxL = 0;
    bool exist = false;

    for (ll l = 1; l <= 9; l++)
    {
        // cout << "it" << endl;
        // cout << l << endl;

        if(paint[l] <= p){
            exist = true;
            ll l_it = p / paint[l];
            ll v_it = 0;
            if(l_it >= maxL){
                ll pot = l_it;
                while(l_it){

                    v_it += pow(10,pot)*l;

                    l_it--;
                    pot--;
                }
                if(maxV < v_it){
                    maxV = v_it;
                    maxL = l_it;
                }
            }
        }else{
            continue;
        }
        // for (int r = l + 1; r <= 9; r++)
        // {
        //     if( paint[r] >= p)continue;
        //     ll ll_it = p / (paint[l]);
        //     ll lr_it = p / (paint[r]);

        //     ll l_it = lr_it + ll_it;
        //     ll v_it = 0;

        //     if(l_it < maxL)continue;
        
        //     if(r > l){
        //         ll pot = l_it;
        //         while(l_it){
        //             if(lr_it){
        //                 v_it += pow(10,pot)*r;
        //                 lr_it--;
        //             }else{
        //                 v_it += pow(10,pot)*l;
        //                 ll_it--;
        //             }
        //             pot--;
        //             l_it--;
        //         }
        //     }else{
        //         ll pot = l_it;
        //         while(l_it){
        //             if(ll_it){
        //                 v_it += pow(10,pot)*l;
        //                 ll_it--;
        //             }else{
        //                 v_it += pow(10,pot)*r;
        //                 lr_it--;
        //             }
        //             pot--;
        //             l_it--;
        //         }
        //     }
        // }
    }
    
    if(exist){

    cout << maxV << endl;
    }else{
        cout << "-1" << endl;
    }

   return 0;
}