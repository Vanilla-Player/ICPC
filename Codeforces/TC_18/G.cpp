#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
long long n,m,k;



ld x[2001];
ld y[2001];

vector<int> apariciones(26,0);


int main(){

    cout << fixed;
    cout.precision(10);

    ld r;

    cin >> n >> r;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        ld disk = r;
        for (int j = 0; j < i; j++)
        {
            if(abs(x[i] - x[j]) > 2*r) continue;
            auto pot = [](ld x) { return x * x; }; // Good for
            ld ny = y[j] + sqrt(pot(2*r)-pot(x[i]-x[j])); // Can i pre calculate 2*r
            disk = max(disk,ny);
        }
        y[i] = disk;

        cout << disk << " ";

    }
    cout << "\n";
    

}