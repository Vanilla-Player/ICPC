#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))

typedef long long ll;
typedef pair<int,int> ii;
const int MAXN=1002;
vector<ll> P;
vector<ll>C;
ll n,m;

vector<vector<ll> >dp(1002,vector<ll>(1002, INT_MAX));
vector<vector<ll> >visited1(1002,vector<ll>(1002, 0));
vector<vector<ll> >steps(1002,vector<ll>(1002, INT_MAX));
map<pair<pair<ll,ll>,pair<ll,ll>>, ll> visited2;
map<pair<pair<ll,ll>,pair<ll,ll>>, ll> movimientos2;
vector<string> sotano;
ll ans = 0;
// D, R, U, L
vector<ll> movx = {1,0,-1,0};
vector<ll> movy = {0,1,0,-1};
string movs = "DRUL";

vector<ll> direc = {3,4,1,2};

bool gotfind = false;

ll solve(ll x1,ll y1,ll x2, ll y2, ll space, ll dir ){


    if(gotfind){
        return INT_MAX;
    }
    dprint("ESTADO");
    dprint(space);
    dprint(x1);
    dprint(y1);
    dprint(x2);
    dprint(y2);
    
    if(space == 1 && sotano[x1][y1] == 'E'){
        cout << "find" << endl;
        gotfind = true;
        return 0; // 1 o 0??
    }

    if(space == 2 && visited2[make_pair(make_pair(x1,y1),make_pair(x2,y2))]){
        return movimientos2[make_pair(make_pair(x1,y1),make_pair(x2,y2))];
    }
    if(space == 2){
        visited2[make_pair(make_pair(x1,y1),make_pair(x2,y2))] = 1;
    }
    

    if(space == 1 && visited1[x1][y1]){
        return dp[x1][y1];
    }
    if(space == 1){
        visited1[x1][y1] = 1;
    }

    if(space == 1){
        forr(i,0,4){
            if(space == 1){ // voy a dos posiciones uso solo x1 y1 para formarlas
                if(x1 + movx[i] < n && x1 + movx[i] >= 0 &&  y1 + movy[i] < m && y1 + movy[i] >= 0 && x1 + 2*movx[i] < n && x1 + 2*movx[i] >= 0 &&  y1 + 2*movy[i] < m && y1 + 2*movy[i] >= 0){// chequeo que sean dentro del rango
                    if(sotano[x1 + movx[i]][y1 + movy[i]] != '#' && sotano[x1 + 2*movx[i]][y1 + 2*movy[i]] != '#'){// Cheuqeo que sean lugares disponibles

                        // dprint("Movement");
                        // dprint(x1 + movx[i]);
                        // dprint(y1 + movy[i]);
                        // dprint(x1 + 2*movx[i]);
                        // dprint(y1 + 2*movy[i]);
                        // dprint(sotano[x1 + 2*movx[i]][y1 + 2*movy[i]]);
                        // break;
                        dp[x1][y1] = min(dp[x1][y1], solve(x1 + movx[i], y1 + movy[i], x1 + 2*movx[i], y1 + 2*movy[i], 2, direc[i]) + 1);
                        if(dp[x1][y1] < INT_MAX){
                        steps[x1][y1] = min(dp[x1][y1], steps[x1][y1]);
                        
                        }
                        
                    }
                }  
            }
        }
    }else{
        if(x1 == x2){ // Si esta horizontal me muevo a la derecha 1 izq 1 arriba 2 abajo 2
            ll derecha = INT_MAX;
            // dprint("PLANCHADA");
            // dprint(dir);
                    ll izquierda = INT_MAX;
                    if(y1 > y2){
                        if(y1 + 1 < m && sotano[x1][y1 + 1] != '#' ){
                            derecha = min(derecha,  solve(x1, y1 + 1, 0, 0, 1,2) + 1); // Aca me muevo a la derecha
                        }
                        if(y2 - 1 >= 0 && sotano[x2][y2 - 1] != '#'){
                            izquierda = min(izquierda, solve(x2, y2 - 1, 0, 0, 1,4) + 1);
                        }

                    }else{
                        // dprint("Te encontre");
                        // dprint(dir);
                        if(y2 + 1 < m && sotano[x2][y2 + 1] != '#'){
                            derecha = min(derecha,  solve(x2, y2 + 1, 0, 0, 1,2) + 1);
                        }
                        if(y1 - 1 >= 0 && sotano[x1][y1 - 1] != '#' ){
                            izquierda = min(izquierda, solve(x1, y1 - 1, 0, 0, 1, 4) + 1);
                        }
                    }
                    ll arriba = INT_MAX;
                    ll abajo = INT_MAX;
                    if(x1 + 1 < n && sotano[x1+1][y1] != '#' && sotano[x2+1][y2] != '#'){
                        arriba = min(arriba, solve(x1+1, y1, x2+1, y2,1, 3)+1);
                    }
                    if(x1 - 1 >= 0 &&sotano[x1 - 1][y1] != '#' && sotano[x2 - 1][y2] != '#'){
                        abajo = min(abajo, solve(x1-1, y1, x2-1, y2,2, 1)+1);
                    }

                    movimientos2[make_pair(make_pair(x1,y1),make_pair(x2,y2))] = min4(arriba,abajo,izquierda,derecha);
                    if(movimientos2[make_pair(make_pair(x1,y1),make_pair(x2,y2))] < INT_MAX){
                        steps[x1][y1] = movimientos2[make_pair(make_pair(x1,y1),make_pair(x2,y2))];
                        steps[x2][y2] = movimientos2[make_pair(make_pair(x1,y1),make_pair(x2,y2))];
                    }
        }else if( y1 == y2){ // aca es al reves de arriba
                    ll derecha = INT_MAX;
                    ll izquierda = INT_MAX; // En realidad aca es arriba abajo
                    if(x1 > x2){
                        if(x1 + 1 < n && sotano[x1+1][y1] != '#'){
                            derecha = min(derecha,  solve(x1 + 1, y1, 0, 0, 1, 3) + 1); // Aca me muevo a la derecha
                            cout << "Return 1 de solucion" << endl;
                            dprint(derecha);
                        }
                        if(x2 - 1 >= 0 && sotano[x2 - 1][y2] != '#'){
                            izquierda = min(izquierda, solve(x2 - 1, y2, 0, 0, 1, 1) + 1);
                        }

                    }else{
                        return 1;
                        if(x2 + 1 < n && sotano[x2 + 1][y2] != '#'){
                            derecha = min(derecha,  solve(x2 + 1, y2, 0, 0, 1,3) + 1);
                        }
                        if(x1 - 1 >= 0 && sotano[x1 - 1][y1] != '#'){
                            izquierda = min(izquierda, solve(x1 - 1, y1 , 0, 0, 1, 1) + 1);
                        }
                    }
                    ll arriba = INT_MAX;
                    ll abajo = INT_MAX;
                    if(y1 + 1 < m && sotano[x1][y1 + 1] != '#' && sotano[x2][y2 + 1] != '#'){
                        arriba = min(arriba, solve(x1, y1+1, x2, y2+1,2, 2)+1);
                        cout << "RETURN DE LA SOLUCION" << endl;
                        dprint(arriba);

                    }
                    if(y1 - 1 >= 0 &&sotano[x1][y1 - 1] != '#' && sotano[x2][y2 - 1] != '#'){
                        abajo = min(abajo, solve(x1-1, y1-1, x2, y2-1,2, 4)+1);
                    }

                    dprint(arriba);
                    dprint(abajo);
                    dprint(izquierda);
                    dprint(derecha);
                    ll r = min4(arriba,abajo,izquierda,derecha);
                    dprint(r);
                    dprint(x1);
                    dprint(y1);
                    dprint(x2);
                    dprint(y2);
                    movimientos2[make_pair(make_pair(x1,y1),make_pair(x2,y2))] = min4(arriba,abajo,izquierda,derecha);
                    if(movimientos2[make_pair(make_pair(x1,y1),make_pair(x2,y2))] < INT_MAX){
                        steps[x1][y1] = min(movimientos2[make_pair(make_pair(x1,y1),make_pair(x2,y2))],steps[x1][y1]);
                        steps[x2][y2] = min(movimientos2[make_pair(make_pair(x1,y1),make_pair(x2,y2))],steps[x2][y2]);
                    }
                }

        }

    if(space == 1){
        // dprint(dp[x1][y1]);
        return dp[x1][y1];
    }else{
        return movimientos2[make_pair(make_pair(x1,y1),make_pair(x2,y2))]? movimientos2[make_pair(make_pair(x1,y1),make_pair(x2,y2))]: INT_MAX; // PUEDE SER QUE NO SE CREE
    }

}


int  main(){



    cin >> n >> m;
    forn(i,n){
        string   s;
        cin >> s;
        sotano.push_back(s);
    }

    ll startI, startJ;
    ll endI, endJ;
    forn(i,n){
        forn(j,m){
            if(sotano[i][j] == 'C'){
                startI = i;
                startJ = j;
            }
            if(sotano[i][j] == 'E'){
                endI = i;
                endJ = j;
            }
        }
    }


    solve(startI,startJ,0,0, 1, 0);

    if(gotfind){
        cout << dp[startI][startJ] << endl;

        int space = 1;
        ll x1 = startI; 
        ll y1 = startJ; 
        steps[endI][endJ] = 0;
        string yecorrido = "";

        int ready = 0;

        while(x1 != endI || y1 != endJ){
            cout << "Bucle" << endl;
            ll cortito = 0;
            ll c1 = x1;
            ll c2 = y1;
            forn(i,4){
                if(x1 + movx[i] >=0 && x1 + movx[i] < n && y1 + movy[i] >=0 && y1 + movy[i] < m){
                    dprint(steps[c1][c2]);
                    dprint(steps[c1 + movx[i]][c2 + movy[i]]);
                    if(steps[c1][c2] >=  steps[c1 + movx[i]][c2 + movy[i]]){
                        if(steps[c1 + movx[i]][c2 + movy[i]] == 0 && c1 + movx[i] == endI && c2 + movy[i] == endJ){
                            c1 = endI;
                            c2 = endJ;
                            cortito = i;
                            ready = 1;
                            break;
                        }
                        if(steps[c1][c2] >  steps[c1 + movx[i]][c2 + movy[i]]){
                            cortito = i; // para saber el movimiento
                            c1 = c1 + movx[i];
                            c2 = c2 + movy[i];
                        }
                        if(steps[x1][y1] ==  steps[c1 + movx[i]][c2 + movy[i]]){
                            // si es igual, no necesito el movimiento
                            c1 = c1 + movx[i];
                            c2 = c2 + movy[i];
                        }
                        
                    }
                }
            }

            if(ready){
                yecorrido += movs[cortito];
                break;
            }
            if(steps[c1][c2] < steps[x1][y1]){
                yecorrido += movs[cortito];
            }
            x1 = c1;
            y1 = c2;

        }
        cout << yecorrido << endl;

        forn(i,n){
            forn(j,m){
                cout << steps[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        cout << -1 << endl;
    }

}