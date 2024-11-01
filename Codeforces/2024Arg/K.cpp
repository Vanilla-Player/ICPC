#include <bits/stdc++.h>
using namespace std;

#define fori(i,n) for(int i=0; i<(n);i++)
#define fora(i,a,n) for(int i=(a); i<=(n);i++)
#define ford(i,a) for(int i=(a); i>=0;i--)

#define dprint(v) cout << #v"=" << v << endl //;)

const int MAX_N = 1000;

vector<string>art;
vector<vector<int> >visited(MAX_N, vector<int>(MAX_N,0)); // 

int n,m, as = 0, ps = 0, ts = 0;



void completeT(int row, int col){
    int offset = 1;
    while(offset < 3){
        visited[row - offset][col] = 1;
        offset++;
    }
    offset-=1;
    row -= offset;
    visited[row][col + 1] = 1;
    visited[row][col - 1] = 1;
    return;
}

void completeP(int row, int col){
    int offset = 1;
    while(offset < 3){
        visited[row - offset][col] = 1;
        visited[row][col + offset] = 1;
        offset++;
    }
    offset-=1;
    row -= offset;
    visited[row][col + 1] = 1;
    visited[row][col + 2] = 1;
    visited[row + 1][col + 2] = 1;
    return;
}

void completeA(int row, int col){
    int offset = 1;
    while(offset < 3){
        visited[row - offset][col] = 1;
        visited[row][col - offset] = 1;
        offset++;
    }
    offset-=1;
    row -= offset;
    visited[row][col - 1] = 1;
    visited[row][col - 2] = 1;
    visited[row + 1][col - 2] = 1;
    row += offset;
    col -= 2;
    offset = 1;
    while(offset < 3){
        visited[row + offset][col] = 1;
        offset++;
    }
    
    return;
}


void solve(int row, int col){

    visited[row][col] = 1;
    // cout << "Entro" << endl;
    // dprint(row);
    // dprint(col);

    bool isT = false;
    bool isP = false;
    bool isA = false;

    int offset = 1;
    while(offset<=2){// Si o si pasa
        visited[row - offset][col] = 1;
        offset++;
    }
    offset-=1;
    row -= offset;

    // cout << "Salios" << endl;
    // dprint(row);
    // dprint(col);
    // // If it's a T
    // dprint(art[row][col - 1]);
    // dprint(art[row][col + 1]);

    if(col + 1 < m && col - 1 >= 0 && (visited[row][col + 1] || art[row][col + 1] == '.') && (visited[row][col - 1] || art[row][col - 1] == '.')){
        isT = true;
        // cout << "IS T" << endl;
        completeT(row, col);
        ts++;
        return;

    }
    // Maybe is a P
    if(!isT && col + 1 < m && row - 1 < n && (art[row][col + 1] == '#' && !visited[row][col + 1]) && (art[row - 1][col + 1] == '.' && !visited[row - 1][col + 1])){
        isP = true;
        // cout << "IS P" << endl;
        completeP(row, col);
        ps++;
        return;

    }

    if(!isT && !isP){ // Despues ver si esto hay que chequear, o no
        isA = true;
        // cout << "IS A" << endl;
        completeA(row, col);
        as++;
        return;
    }

}


int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    fori(i,n){
        string row;
        cin >> row;
        art.push_back(row);
    }


    ford(i,n - 1){
        ford(j, m - 1){
            // cout << "IN" << endl;
            if(art[i][j] == '#' && !visited[i][j]){
                solve(i,j);
            }
        }
    }


    cout << ts << " " << as << " " << ps << endl;

}