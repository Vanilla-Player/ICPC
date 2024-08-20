#include <bits/stdc++.h>

using namespace std;

#define ll long long

long long n,m,k;



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        ll a,b,c;

        cin >> a >> b >> c;



        if(a > b){
            swap(a,b);
        }

        a+=b;
        ll count = 1;

        while(c >= a && c >=b){

            if(count % 2 == 1){
                b+=a;
            }else{
                a+=b;
            }
            count++;
        }

        cout << count << endl;

    }


}