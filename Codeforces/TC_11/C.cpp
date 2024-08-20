
#include <bits/stdc++.h> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 
#define ll long long
#define MAX_N 1001
string s;
long long n;
// vector<vector<ll> > dp(1001,vector<ll>(MAX_N,1));


int main()
{
    fast_io;

    int w,h;
    cin >> w >> h;  

    long long mod = 998244353;
    long long res = 4;
    for (int i = 1; i <= w+h-2; i++) {
		res *= 2;
		res %= mod;
	}
    
    cout <<  res << endl; 


   return 0;
}