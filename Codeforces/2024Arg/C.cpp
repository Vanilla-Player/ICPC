#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fori(i,n) for(int i = 0; i < (n);i++)
#define fora(i,a,n) for(int i = (a); i <= (n);i++)
#define ford(i,a) for(int i = (a); i >= 0 ;i--)

const ld EPS = 1e-8;

struct pt
{
    ld x,y;
    pt(ld x, ld y):x(x),y(y){}
    pt(){}
    pt operator+(pt p){return pt(x+p.x, y+p.y);} 
    pt operator-(pt p){return pt(x-p.x, y-p.y);} 
    ld operator*(pt p){return 1LL*(x*p.x+y*p.y);} 
    ld operator&(pt p){return 1LL*((x*p.y)-(y*p.x));} 
};


ll lados;
vector<pt>polygonZ;

int main(){

    cin >> lados;

    ld xc,yc,zc,xs,ys,zs;
    
    cin >> xc >> yc >> zc;
    cin >> xs >> ys >> zs;
    ld lam = -(zc/(zc - zs));
    ld xp, yp;
    xp = xc + (xc - xs)*lam;
    yp = yc + (yc - ys)*lam;

    pt ps(xp,yp);

    for (int i = 0; i < lados; i++)
    {
        ld x,y;
        cin >> x >> y;
        pt p = {x,y};
        polygonZ.push_back(p);
    }
    

    ld area = 0;
    for (int i = 0; i < lados ; i++)
    {
        area += polygonZ[i%lados] & polygonZ[(i+1)%lados];
    }

    ld areaSombra = 0;
    for (int i = 0; i < lados; i++)
    {
        pt p1 (polygonZ[i%lados].x,polygonZ[i%lados].y);
        pt p2 (polygonZ[(i+1)%lados].x,polygonZ[(i+1)%lados].y);

        // ok entonces hago
        // areaSombra += abs((p1.x*ps.y - p1.y*ps.x) + +(ps.x*p2.y - ps.y*p2.x) + (p2.x*p1.y - p2.y*p1.x));
        areaSombra += abs((p1.x * (p2.y - ps.y)) + (p2.x * (ps.y - p1.y)) + (ps.x * (p1.y - p2.y)));
    }   

    // cout << (areaSombra) << endl;
    // cout << (area) << endl;


    // if(abs(areaSombra) == abs(area) && sgn(areaSombra) != sgn(area)){
    //      cout << "N" << endl;
    // }else 
    if(abs(areaSombra) - abs(area) > EPS){
        cout << "S" << endl;
    // }else if(sgn(areaSombra) == sgn(area)){
    //     cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }
    

    // cout << "lam: " << lam << endl;
    
    // cout << ps.x << " " << ps.y << endl;

}