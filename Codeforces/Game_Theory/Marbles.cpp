#include <bits/stdc++.h>

using namespace std;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
#define fill(a, v) memset(a, v, sizeof(a))


const int MAXN = 1000;

int mex[101][101];

bool used[1001];

int cal_mex(int di, int dj){

    fill(used,0);
    fora(i,0, di - 1){
       used[mex[i][dj]] = true;
    }

    fora(j,0, dj - 1){
       used[mex[di][j]] = true;
    }

    int mini = min(di,dj);

    fora(i, 1, mini){
        used[mex[di-i][dj-i]] = true;
    }

    fori(i,1000){
        if(!used[i]){
            return i;
        }
    }

    cout << "Ret" << endl;
    cout << "i: " << di << " j: " << dj << "\n";
    return 0;

}

int main(){

    fill(mex,0);

    fori(i,101){
        mex[i][0] = 999;
        mex[0][i] = 999;
        mex[i][i] = 999;
    }

    fora(i,1,100){
        fora(j,1,100){
            if(i != j){
                mex[i][j] = cal_mex(i,j);
            }
        }
    }

  

    int n,a,b;

    cin >> n;

    int g = 0;
    while(n--){
        cin >> a >> b;
    
        // cout << "mex: " << mex[a][b] << "\n";
        if(mex[a][b] == 999){
            cout << "Y" << endl;

            return 0;
        }

        g ^= mex[a][b];
    }

    // cout << "g: " << g << "\n";
    if(g){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }


}