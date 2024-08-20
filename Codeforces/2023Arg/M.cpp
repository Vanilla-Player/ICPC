#include <bits/stdc++.h>


using namespace std;


int main(){

    long long N,T;

    cin >> N >> T;


    long double sum = 0;
    for (int i = 0; i < N; i++)
    {
        long long t;
        char x;
        cin >> x >> t;
        sum+= t;

    }

    sum/=T;

    cout << setprecision(9) ;

    cout << sum << endl;

    return 0;
     
}