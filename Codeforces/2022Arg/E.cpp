#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

#define fori(i,n) for(int i = 0; i<(n);i++)
#define fora(i,a,n) for(int i = a; i<=(n);i++)
#define ford(i,a,n) for(int i = a; i>=(n);i--)
#define dprint(v) cout << #v"=" << v << endl //;

#define fi first
#define se second
#define mp make_pair
#define pb push_back


int main(){

    ll n;
    cin >> n;
    vl dir1;
    vl dir0;

    fori(i,n){
        ll time, dir;
        cin >> time >> dir;

        if(dir == 0){
            dir0.pb(time);
        }else{
            dir1.pb(time);
        }
    }

    ll dir = 2;
    ll time = 0;

    cout << "cRGE" << endl;

    if(dir1.size() == 0){
        dir = 0;
        time = dir0[0];
    }
    if(dir0.size() == 0){
        dir = 0;
        time = dir1[0];
    }

    if(dir1.size() !=0 && dir0.size() != 0){

        if(dir0[0] < dir1[0]){
            dir = 0;
            time = dir0[0];
        }else{
            dir = 1;
            time = dir1[0];
        }

    }

    ll rw0 = 0;
    ll rw1 = 0;
    ll sz1 = dir1.size();
    ll sz0 = dir0.size();
    bool st = true;
    while(rw0 < sz0 || rw1 < sz1){
        
        

        while(rw0 < sz0 && rw1 < sz1 && (dir0[rw0] <= dir1[rw1]+10 || dir0[rw0]+10 >= dir1[rw1])){
            cout << "Entre" << endl;
            if(dir == 0)
            {
                while(rw0 + 1 < sz0 && dir0[rw0 + 1] <= dir0[rw0]+10)rw0++;
                if(st){
                    time += dir0[rw0]+10;
                }else{
                    time+=10;
                }
                // aca tengo que ver si hay algun valor menor que dir0[rw0]+10 en la otra lista
                if(rw1 < sz1 && dir1[rw1] <= dir0[rw0]+10){
                    while( rw1 +1 < sz1 && dir1[rw1 + 1] <= dir0[rw0]+10)rw1++;
                    time+=10;
                    dir = 1;
                }
            }
            if(dir == 1){
            while(rw1 +1 < sz1 && dir1[rw1 + 1] <= dir1[rw1]+10)rw1++;
                if(st){
                    time += dir1[rw1]+10;
                }else{
                    time+=10;
                }
                if(rw0 < sz0 && dir0[rw0] <= dir1[rw1]+10){
                    while(rw0 + 1 < sz0 && dir0[rw0 + 1] <= dir1[rw1]+10)rw0++;
                    time+=10;
                    dir = 0;
                }
            } 
        }
         // obtengo los ultimos que no se pisan 

        if(rw0 + 1 <= sz0 && rw1 + 1 <= sz1){
            if(dir0[rw0 + 1] < dir1[rw1 + 1]){
                st = true;
                time+= dir0[rw0 + 1] - time;
                rw0++;
            }else{
                st = true;
                time+= dir1[rw1 + 1] - time;
                rw1++;
            }
        }else if(rw0 + 1 <= sz0){
            st = true;
            time += dir0[rw0 + 1] - time;
            rw0++;
        }else if(rw1 + 1 <= sz1){
            st = true;
            time += dir1[rw1 + 1] - time;
            rw1++;
        }


        // Lo que pasa es que se pueden sumar mas numeros al final de cada una

    }

    cout << time << endl;

    return 0;
}




