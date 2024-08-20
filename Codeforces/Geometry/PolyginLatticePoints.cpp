#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define ld long double

int gcd(int a, int b) {
       if (b == 0) return a;
       return gcd(b, a%b);
}


struct pt{
    ll x, y;
    pt(ll x, ll y):x(x),y(y){}
    pt(){}
    pt operator-(pt p){return{p.x-x,p.y-y};}
    pt operator+(pt p){return{p.x+x,p.y+y};}
    ll operator^(pt p){return 1LL*(p.y*x-p.x*y);}
    ld norm() { return sqrt(x*x + y*y); }
    ld dist(pt b) { return (b - (*this)).norm(); }
};


int main(){

    ll n;
    cin >> n;
    vector<pt>polygonZ;
    for (int i = 0; i < n; i++)
    {
        ll x,y;
        cin >> x >> y;
        polygonZ.push_back({x,y});
    }
    polygonZ.push_back(polygonZ[0]);
    ll area = 0;
    ll b = 0; 
    for (int i = 0; i < n; i++)
    {
        pt v1 = polygonZ[i];
        pt v2 = polygonZ[i+1];
        area += v1^v2;

        pt seg = v2 - v1;

        ll g = gcd(seg.x,seg.y);
        b+= abs(g);

    }
    
    // a + b/2 - 1 = area ; a points inside , b at the edge. => 2area - b + 2 = 2a ; 
    ll a = abs(area) - b + 2; // area is not area*2 because formula calculate area with (1/2)*abs(sum(p1xp2,...,pnxp1)) so 2/2 = 1
    cout << a/2 << " " << b << "\n";
    
}