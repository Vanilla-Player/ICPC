#include <bits/stdc++.h>
#define ll long long

using namespace std;


struct pt
{
    ll x,y;
    pt(ll x, ll y):x(x),y(y){}
    pt(){}
    pt operator+(pt p){return pt(x+p.x, y+p.y);} 
    pt operator-(pt p){return pt(x-p.x, y-p.y);} 
    ll operator*(pt p){return 1LL*(x*p.x+y*p.y);} 
    ll operator&(pt p){return 1LL*((x*p.y)-(y*p.x));} 
};


int main(){

    // pt v = {3,2};

    int t;
    cin >> t;
    while(t--){
        vector<pt>points(3);
        for(int i = 0; i < 3; i++){
            ll x,y;
            cin >> x >> y; 
            pt v = {x,y};
            // cout << "Vecor" << "\n";
            points[i] = v;
            // cout << points[i].x << " " << points[i].y << "\n";
        }
        
        ll result = (points[2]-points[0])&(points[2]-points[1]);

        if(result > 0){
            cout << "LEFT" << "\n";
        }else if( result < 0){
             cout << "RIGHT" << "\n";
        }else{
            cout << "TOUCH" << "\n";
        }

    }


}