#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){

        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false; 
            }
        }

    return true;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    bool numberISFINE = false;

    if(n == 0 || n == 1){
        numberISFINE = true;
    }

    while(!numberISFINE){

        if(!isPrime(n)){
            numberISFINE = true;
        }else{
            n++;
        }
        
    }
    cout << n;

}