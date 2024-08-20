#include <bits/stdc++.h>

using namespace std;

#define ll long long

long long n,m,k;



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);


        long long min = 1e18;
        long long max = 0;
        long long ant;
        long long equals = 1;

        for (int i = 0; i < 3; i++)
        {
            long long num;
            cin >> num;
            if(i == 0){
                ant = num;
            }else if(i!=0){
                if(ant == num){
                    equals++;
                }
            }
            if(num > max){
                max = num;
            }else if(num < min){
                min = num;
            }
        }

        if(equals == 3){
            cout << "0"<< endl;    
        }else{
            cout << 1LL*((max - 1) - min) << endl;
        }

}