#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define fori(i,n) for(int i = 0; i < (n); i++)
#define fora(i,a,n) for(int i = (a); i <= (n); i++)
#define ford(i,a,n) for(int i = (a); i >= (n); i++)

#define pb push_back
#define mp make_pair

#define dprint(v) cout << #v"=" << v << endl //;)


const int INF = 1000000007;
const int MOD = 1000000007;
const int MAX = 100000004;


int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    vector<int> cartasE(3);
    vector<int> cartasA(3);
    bool jugadasA[3];
    bool jugadasE[3];

    fori(i,3){
        cin >> cartasE[i];
    }
    sort(cartasE.begin(), cartasE.end());

    int sum = cartasE[0] + cartasE[1] + cartasE[2];
    int sum_ad = 0;
    int dif = cartasE[0];
     int cantidad = 0;
    fora(i,1,cartasE[0] - 1){
        if(cantidad > 2){
            break;
        }
        cartasA[cantidad]=i;
        cantidad++;
    }
    fora(i,cartasE[0] + 1,cartasE[1] - 1){
         if(cantidad > 2){
            break;
        }
         cartasA[cantidad]=i;
        cantidad++;
    }
    fora(i,cartasE[1] + 1,cartasE[2] - 1){
         if(cantidad >= 3){
            break;
        }
         cartasA[cantidad]=i;
        cantidad++;
    }

    fora(i,cartasE[2]+1, 7){
         if(cantidad >= 3){
            break;
        }
        cartasA[cantidad]=i;
        cantidad++;
    }
    sort(cartasA.begin(), cartasA.end());
    //MEN A MAYOR
    int manos = 0;
    if(cartasE[2] < cartasA[2]){
        if(cartasE[2] < cartasA[1]){
            if(cartasE[2] < cartasA[0]){
                cout << "S" << endl;
                return 0;
            }else{
                jugadasA[0] = true;
                jugadasE[2] = true;
            }
        }else{
            jugadasA[1] = true;
        }
    }else{
        jugadasA[2] = true;
    }

    if(jugadasA[2]){
        // comparo 0 1 
        if(cartasE[1] < cartasA[1]){
            if(cartasE[1] < cartasA[0]){
                cout << "S" << endl;
                return 0;
            }else{
                jugadasA[0] = true;
                jugadasE[1] = true
            }
        }else{
            jugadasA[1] = true;
        }
    }

    if(jugadasA[1]){
        if(cartasE[1] < cartasA[2]){
            if(cartasE[1] < cartasA[0]){
                cout << "S" << endl;
                return 0;
            }else{
                jugadasA[0] = true;
                jugadasE[1] = true
            }
        }else{
            jugadasA[2] = true;
        }
    }

    if(jugadasA[1] && jugadas[2]){

    }

    if(manos >= 2){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }

}