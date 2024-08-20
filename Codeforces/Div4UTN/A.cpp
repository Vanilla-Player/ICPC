#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){

    int  t;


    cin >> t;

    while(t--){
        int N1,N2,N3;
        cin >> N1 >> N2 >> N3;
        int number = 0;
        if(N1 != N2 && N1 != N3){
            cout << N1 << endl;
            continue;
        }

        if(N2 != N3 && N2 != N1){
            cout << N2 << endl;
            continue;
        }
        cout << N3 << endl;
    }

    return 0;
}