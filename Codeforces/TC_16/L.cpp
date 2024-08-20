#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, qx,qy,kx,ky,cx,cy;

    cin >> n;
    cin >> qx >> qy;
    cin >> kx >> ky;
    cin >> cx >> cy;

    bool finished = false;

    if((kx < qx) && (cx < qx) || (kx > qx) && (cx > qx)){

        if((ky < qy) && (cy < qy) || (ky > qy) && (cy > qy)){
            finished = true;
        }
    }

    if(finished){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}