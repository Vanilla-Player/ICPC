#include <bits/stdc++.h>

using namespace std;


const int MAX_N = 1000;

// Solo recorro los que estan unidos
vector<pair<int, pair<int,int> > >graphina; // Asi tengo que guardar el grafo
int link[MAX_N]; // Tienen el nodo que representa el grupo
int sizeComp[MAX_N]; // El tamanio de la componente



int find(int x){
    while(x != link[x]) x = link[x]; // Busco el nodo que representa a x
    return x;                       // Rompe cuando el link[x] = x entonces el nodo que representa al x inical es x'
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(sizeComp[a] < sizeComp[b]) swap(a,b); // "Conecto" el grupo mas chiquito al mas grande
    sizeComp[a] += sizeComp[b];
    link[b] = a;
}

bool same(int a, int b){
    return find(a) == find(b);
}

int main(){

    int v, n;
    cin >> v >> n;

    for(int i = 0; i < n;i++){
        int a,b,w;
        cin >> a >> b >> w;
        graphina.emplace_back(make_pair(w, make_pair(a, b)));
    }
    sort(graphina.begin(), graphina.end());

    for (int i = 1; i <= v; i++)
    {
        link[i] = i;
        sizeComp[i] = 1;
    }
    

    int result = 0;
    for (int i = 0; i < graphina.size(); i++){
        int a = graphina[i].second.first;
        int b = graphina[i].second.second;
        int w = graphina[i].first;
        if(!same(a,b)){
            unite(a,b);
            result+=w;
        }
    }
    cout << result << endl;

}