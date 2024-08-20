
#include <bits/stdc++.h>



using namespace std;


typedef long long L;
typedef complex<L> P;
#define X real()
#define Y imag()

const L INF = 1e9 + 7;


vector<P>polygonZ;

bool comp(const P &a, const P &b) {
    return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
}


L crossProduct(P A, P B, P C){
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

L sgn(L x) {
    return (x > 0) - (x < 0);
}

bool check(P A, P B, P C, P D){

    L cp1 = sgn(crossProduct(A,B,C));
    L cp2 = sgn(crossProduct(A,B,D));
    L cp3 = sgn(crossProduct(C,D,A));
    L cp4 = sgn(crossProduct(C,D,B));
    if (cp1 * cp2 < 0 && cp3 * cp4 < 0) return 1;
        
    if(cp4 == 0 && isMid(C,D,B) && cp3 < 0)return 1;
    return 0;
}


int main(){

    L n,m;
    cin >> n >> m;

    for (L i = 0; i < n; i++)
    {
        L x,y;
        cin >> x >> y;
        P p = {x,y};
        polygonZ.push_back(p);
    }
    polygonZ.push_back(polygonZ[0]);

    while (m--)
    {
        L x,y;
        cin >> x >> y;
        P a = {x,y};
        P b = {INF,INF};
        bool isBoundary = false;

        L cnt = 0;
        for (L i = 0; i < n ; i++)
        {
            L crs = sgn(crossProduct(polygonZ[i], polygonZ[i+1], a));

            if(crs == 0 && isMid(polygonZ[i], polygonZ[i+1], a)){
                isBoundary = true;
                break;
            }

            cnt +=check(polygonZ[i], polygonZ[i+1], a,b); // intersecciona algun segmento del polygono?

        }
        
        // Si intersecciona algun segmento, entonces lo hara numero impares de veces
        if (isBoundary) cout << "BOUNDARY" << endl;
        else cout << (cnt & 1 ? "INSIDE" : "OUTSIDE") << endl;
    }


}