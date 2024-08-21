#include <bits/stdc++.h>

#define MAX_N 100005
using namespace std;

typedef long long ll;

typedef pair<int,int> P;
int Q;
vector<bool>dead(MAX_N,false);
int king, id;
vector<int> family[MAX_N];
int father[MAX_N];
int hijos_revisados[MAX_N];

void getSuccesor(){

    while(dead[king]){
        if(family[king].size() == hijos_revisados[king])(king = father[king]);
        else{
            //Aumento la pos del hijo
            hijos_revisados[king]++;
            king  = family[king][hijos_revisados[king] - 1];
        }
    }

}

int main(){


    cin >> Q;
    king = id = 1;

    while(Q--){
        int action, noble;
        cin >> action >> noble;
        if(action == 1){
            id++;
            family[noble].push_back(id);
            father[id] = noble;
        }else{
            // murio
            dead[noble] = true;
            if(dead[king]) getSuccesor();
            cout << king << endl;
        }


    }


}