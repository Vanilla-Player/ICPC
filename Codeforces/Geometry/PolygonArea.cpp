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

    ll n;
    cin >> n;

    vector<pt> polygonZ;

    for (int i = 0; i < n; i++)
    {
        ll x,y;
        cin >> x >> y;
        pt p = {x,y};
        polygonZ.push_back(p);
    }

    // FORMULA TO CALCULATE AREA OF A POLYGON 
    //   ABS(SUM(p1Xp2,p2xp3,...,pn-1xpn))
    //
    ll area = 0;
    for (int i = 0; i < n ; i++)
    {
        area += polygonZ[i%n] & polygonZ[(i+1)%n];
    }
    area = abs(area);

    cout << area << "\n";
    

}