struct pt
{
    ll x,y;
    pt(ll x, ll y):x(x),y(y){}
    pt(){}
    pt operator+(pt p){return pt(x+p.x, y+p.y);} // Suma
    pt operator-(pt p){return pt(x-p.x, y-p.y);} // Resta
    ll operator*(pt p){return 1LL*(x*p.x+y*p.y);} // Producto escalar
    ll operator&(pt p){return 1LL*((x*p.y)-(y*p.x));} // Producto Cruz o Vectorial
    long double norm() {return sqrt(x*x + y*y);} // Norm
    long double dist(pt b) {return (b - (*this)).norm();}
};


