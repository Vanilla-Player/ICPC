#include <bits/stdc++.h>



using namespace std;


    typedef long long L;
    typedef complex<L> P;
    #define X real()
    #define Y imag()

const double eps = 1e-9;

bool comp(const P &a, const P &b) {
    return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
}


int crossProduct(P A, P B, P C){
    P AB = B - A;
    P AC = C - A;

    return(conj(AB)*AC).Y;
}

bool isMid(P A, P B, P C){
    vector<P> v = {A, B, C};
    sort(v.begin(), v.end(), comp);
    if(C == v[1])return 1;
    return 0;
}

int sgn(L x) {
    return (x > 0) - (x < 0);
}

bool check(P A, P B, P C, P D){

    L cp1 = crossProduct(A,B,C);
    L cp2 = crossProduct(A,B,D);
    L cp3 = crossProduct(C,D,A);
    L cp4 = crossProduct(C,D,B);
    if(cp1 == 0 && isMid(A,B,C))return 1;
    if(cp2 == 0 && isMid(A,B,D))return 1;
    if(cp3 == 0 && isMid(C,D,A))return 1;
    if(cp4 == 0 && isMid(C,D,B))return 1;
    if (sgn(cp1) != sgn(cp2) && sgn(cp3) != sgn(cp4)) return 1;
    return 0;
}


int main(){

    int t; cin>>t;
    while (t--) {
        L x, y;
        P a, b, c, d;
        cin >> x >> y; a = {x, y};
        cin >> x >> y; b = {x, y};
        cin >> x >> y; c = {x, y};
        cin >> x >> y; d = {x, y};
        cout << (check(a, b, c, d) ? "YES" : "NO") << endl;
    }

    // vector<pt>points(4);

    // for (int i = 0; i < 4; i++)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     pt v = {x, y};
    //     points[i] = v;
    // }


    // segm seg1 = {points[0],points[1]};
    // segm seg2 = {points[2],points[3]};
    
    // cout << "Line1" << endl;

    // cout << "Result" << endl;
    // cout << seg1.inter(seg2).x << endl;

}

// IMPLEMENTACION CON STRUCTURAS

// struct pt{
//     long double x,y;
//     pt(int x, int y):x(x),y(y){}
//     pt(){}
//     pt operator+(pt p){return pt(x+p.x, y+p.y);}
//     pt operator-(pt p){return pt(x-p.x, y-p.y);}
//     long double operator^(pt p){return int(x*p.y-y*p.x);}
//     pt operator*(ll k) { return pt(x * k, y * k);}
//     long double operator&(pt b) { return (x * b.x+ y * b.y);}
//     pt operator/(ll k) { return pt(x/k, y/k); }
    // long double norm() {return sqrt(x*x + y*y);}
    // long double dist(pt b) {return (b - (*this)).norm();}
// };

struct  line{
    pt p, vd;
    line(pt p, pt vd):p(p), vd(vd){}
    line(){}

    pt inter(line l){
        cout << "Cross product" << endl;
        int res = (vd^l.vd);
        cout << res << endl;
        if(abs(res) <= eps)return pt(9999,9999);

        long double t = ((l.p - p) ^ l.vd) / static_cast<long double>(res);
        //if(vd^l.vd )return  pt(9999,9999); // Numero grande para que entienda que no se intersectan
        return  p+vd*t;
    }
};

// struct segm{
//     pt s, e;
//     segm(pt s, pt e):s(s),e(e){
//     }

//     bool inside(pt b){return abs(s.dist(b) + e.dist(b) - s.dist(e)) < eps;}
//     pt inter(segm b){
//         if((*this).inside(b.s))return b.s;
//         if((*this).inside(b.e))return b.e;

//         pt in = line(s,e).inter(line(b.s,b.e));
//         cout << "in" << endl;
//         cout << in.x << " " << in.y << endl;
//         if((*this).inside(in) && b.inside(in)){
//             return in;
//         }
//         return pt(9999,9999);
//     }

// };

