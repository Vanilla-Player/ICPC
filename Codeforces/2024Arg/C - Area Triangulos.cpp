#include <bits/stdc++.h>
using namespace std;

#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; i++)
#define forn(i, n) forr(i, 0, n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define dforn(i,n) for(int i = n-1; i>=0; i--)
#define pb push_back
#define fst first
#define snd second
#define ln '\n'
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll MOD = 1e9 + 7;
const ll MAXN = 100100;
const ll INF = 9e18;
const ld EPS = 1e-8;


struct pto {
    ld x,y;
    pto (ld x=0, ld y=0):x(x),y(y){}
    pto operator+(pto a){return pto(x+a.x,y+a.y);}
    pto operator-(pto a){return pto(x-a.x,y-a.y);}
    pto operator+(ld a){return pto(x+a,y+a);}
    pto operator*(ld a){return pto(x*a,y*a);}
    pto operator/(ld a){return pto(x/a,y/a);}
    //dot product, producto interno:
    ld operator*(pto a){return x*a.x+y*a.y;}
    //module of the cross product or vectorial product:
    //if a is less than 180 clockwise from b, a^b>0
    ld operator^(pto a){return x*a.y-y*a.x;}
    //returns true if this is at the left side of line qr
    bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
    bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS
    && y<a.y-EPS);}
    bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
    ld norm(){return sqrt(x*x+y*y);}
    ld norm_sq(){return x*x+y*y;}
};

ld dist(pto a, pto b){return (b-a).norm();}

pto intersect(pto c,pto s, ld zc, ld zs) {
    ld lambda = (-zc)/(zs-zc);
    return (c+((s-c)*lambda));
}

int sgn(ll x){return x<0? -1 : !!x;}

struct line{
    line() {}
    ld a,b,c;//Ax+By=C
    //pto MUST store float coordinates!
    line(ld a, ld b, ld c):a(a),b(b),c(c){}
    line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
    int side(pto p){return sgn(ll(a) * p.x + ll(b) * p.y - c);}
};

bool parallels(line l1, line l2){return abs(l1.a*l2.b-l2.a*l1.b)<EPS;}
    pto inter(line l1, line l2){//intersection
    ld det=l1.a*l2.b-l2.a*l1.b;
    if(abs(det)<EPS) return pto(INF, INF);//parallels
    return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
}

//checks if v is inside of P, using ray casting
//works with convex and concave.
//excludes boundaries, handle it separately using segment.inside()
bool inPolygon(pto v, vector<pto>& P) {
    bool c = false;
    forn(i, sz(P)){
    int j=(i+1) %sz(P);
    if((P[j].y>v.y) != (P[i].y > v.y) &&
    (v.x < (P[i].x - P[j].x) * (v.y-P[j].y) / (P[i].y - P[j].y) + P[j].x))
    c = !c;
    }
    return c;
}

struct segm{
    pto s,f;
    segm(pto s, pto f):s(s), f(f) {}
    bool inside(pto p){return abs(dist(s, p)+dist(p, f)-dist(s, f))<EPS
    ;}
};

pto inter(segm s1, segm s2){
    pto r=inter(line(s1.s, s1.f), line(s2.s, s2.f));
    if(s1.inside(r) && s2.inside(r)) return r;
    return pto(INF, INF);
}

bool segmentoPorFuera (vector<pto> &pol, pto p, int n) {
    forn(j,n) {
        forn(i,n) {
            if (i != j && (i+1)%n != j) {
                pto auxPto = inter(segm(p,pol[j]),segm(pol[i],pol[(i+1)%n]));
                if (auxPto.x != INF && auxPto.y != INF) {
                    return true;}
            }
        }
    }
    return false;
}

pto borde1,borde2;
bool inBorder (vector<pto> &pol, pto p, int n) {
    forn(i,n) {
        segm aux = segm(pol[i],pol[(i+1)%n]);
        if (aux.inside(p)) {
            borde1 = pol[i];borde2=pol[(i+1)%n];
            return true;
        }
    }
    return false;
}

//stores convex hull of P in S, CCW order
//left must return >=0 to delete collinear points!
void CH(vector<pto>& P, vector<pto> &S){
    S.clear();
    sort(P.begin(), P.end());//first x, then y
    forn(i, sz(P)){//lower hull
    while(sz(S)>= 2 && S[sz(S)-1].left(S[sz(S)-2], P[i])) S.pop_back();
    S.pb(P[i]);
    }
    S.pop_back();
    int k=sz(S);
    dforn(i, sz(P)){//upper hull
        while(sz(S) >= k+2 && S[sz(S)-1].left(S[sz(S)-2], P[i])) S.pop_back
            ();
        S.pb(P[i]);
    }
    S.pop_back();
}

bool checkMedio (vector<pto> &pol, int n, pto p) {
    forn(i,n) {
        if (!(pol[i] == borde1) && !(pol[i] == borde2)) {
            pto aux = (p+pol[i])/2;
            if (!inPolygon(aux,pol)) return true;
        }
    }
    return false;
}

ld area(vector<pto> &p){//O(sz(p))
    ld area=0;
    forn(i, sz(p)) area+=p[i]^p[(i+1) %sz(p)];
    //if points are in clockwise order then area is negative
    return abs(area)/2;
}
//Area ellipse = M_PI*a*b where a and b are the semi axis lengths
//Area triangle = sqrt(s*(s-a)(s-b)(s-c)) where s=(a+b+c)/2

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    pto c,s;
    ld zc,zs;
    cin >> c.x >> c.y >> zc;
    cin >> s.x >> s.y >> zs;
    vector<pto> pol(n);
    forn(i,n){
        cin >> pol[i].x >> pol[i].y;
    }
    pto aux = intersect(c,s,zc,zs); 
    if (!inPolygon(aux,pol)) cout << "S" << ln;
    else {
        ld areaP = area(pol);
        ld areaAux = 0;
        forn(i,n) {
            vector<pto> triang;
            triang.pb(aux);triang.pb(pol[i]);triang.pb(pol[(i+1)%n]);
            areaAux += area(triang);
            triang.clear();
        }
        if (areaP < areaAux-EPS) cout << "S" << ln;
        else cout << "N" << ln;
    }
}