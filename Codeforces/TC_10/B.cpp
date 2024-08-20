
#include <bits/stdc++.h> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std; 

int main()
{
    fast_io;

    int t;
    ll r, e, d;

    cin >> r >> d >> e;
    ll re = r;
    ll rd = r;
    ll dolars = rd/d;
    if(dolars){
        rd -= d*dolars;
    }
    ll euros = rd/e;
    if(euros / 5){
        rd -= e*euros;
        rd += euros%5;
    }

    euros = re/e;
    if(euros / 5){
        re -= e*euros;
        re += euros%5;
    }
    dolars = re/d;
    if(dolars){
        re -= d*dolars;
    }

    cout << min(rd,re) << endl;
    
    return 0;
}