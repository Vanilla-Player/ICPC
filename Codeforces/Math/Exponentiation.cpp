#include <bits/stdc++.h>


using namespace std;

// Function to calculate the kth child to be removed
long long modPow(long long x, long long b, long long m)
{
    if(b== 0) return 1%m;

    long long u = modPow(x,b/2,m);

    u = (u*u)%m;
    if(b%2 == 1) u = (u*x)%m;
    return u;
}



int main()
{
      long long x, b, c, mod = 1e9 + 7;
      int t;
    cin >> t;
    while(t--){
    cin >> x >> b >> c;
    long long pows = modPow(b, c, mod - 1);
    cout << modPow(x, pows, mod)
             << "\n";
    }
}