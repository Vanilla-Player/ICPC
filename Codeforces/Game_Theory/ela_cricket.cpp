#include <bits/stdc++.h>

#define fill(a, v) memset(a, v, sizeof(a))
#define fori(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int xs[3];
int ys[3];


pair<int,int>get_center(){
    int x = (xs[0] == xs[1])? xs[0] : xs[2];  
    int y = (ys[0] == ys[1])? ys[0] : ys[2];  
    return {x,y};
}

int main(){

    int t;
    cin >> t;

    while(t--){
        fill(xs,0);
        fill(ys,0);
        int n;
        cin >> n;
        fori(i,3){
            cin >> xs[i] >> ys[i];
        }

        pair<int,int> ct = get_center();
        int cx = ct.first;
        int cy = ct.second;
        int x,y;
        cin >> x >> y;
        // cout << "cx: " << cx <<"\n";
        // cout << "cy: " << cy <<"\n";

        if((cx == 1 || cx == n) && (cy == 1 || cy == n)){

            if(cx == x || cy == y){
                cout << "YES" << "\n";
                continue;
            }
            cout << "NO" << "\n";
            continue;
        }

        if(((cx+cy)%2 == (x+y)%2)){// same color 
            if(cx % 2 == x % 2){
                cout << "YES" << "\n";
                continue;
            }
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";



    }
    
}