// Pista: es más fácil contar la cantidad de cuadrilateros concavos
// Pista: un cuadrilatero concavo es un triangulo con un punto adentro
// Pista: por cada punto, contar cuantos triángulos lo contienen
// Pista: por cada punto, ordenar los otros por angulo respecto a ese punto
// Pista: two pointers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fori(i,n) for(int i= 0; i< (n); ++i)
#define fora(i,a,n) for(int i= (a); i<= (n); ++i)
#define ford(i,a,n) for(int i= a; i>= (n); --i)

#define dprint(v) cout << #v"=" << v << endl //;)

struct pt{
    ll x,y;
    pt(ll x, ll y):x(x),y(y){}
    (){}
    pt operator+(pt p){return pt(x+p.x, y+p.y)}
    pt operator-(pt p){return pt(x-p.x, y-p.y)}
    ll operator*(pt p){return 1LL(x*p.x + y*p.y)}
    ll operator&(pt p){return 1LL(x*p.y - y*p.x)}
}

set<pt>used;



