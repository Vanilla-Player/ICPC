vector<pair<int, pair<int,int> > >graphina; // Asi tengo que guardar el grafo
int link[MAX_N]; // Tienen el nodo que representa el grupo
int sizeComp[MAX_N]; // El tamanio de la componente

// Recordar inicializar link y sizeComp
for (int i = 1; i <= v; i++)
{   link[i] = i;
    sizeComp[i] = 1;}

int find(int x){
    while(x != link[x]) x = link[x]; // Busco el nodo que representa a x
    return x;                       // Rompe cuando el link[x] = x entonces el nodo que representa al x inical es x'
}
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(sizeComp[a] < sizeComp[b]) swap(a,b); // "Conecto" el grupo mas chiquito al mas grande
    sizeComp[a] += sizeComp[b]; // Actualizo el size de la componente
    link[b] = a;    
}  
bool same(int a, int b){ // Chequear si estan en la misma componente
    return find(a) == find(b);
}

// Para sortear basta con 
sort(graphina.begin(), graphina.end());
// Para recorrer
int result = 0;
for (int i = 0; i < graphina.size(); i++){
    int a = graphina[i].second.first;
    int b = graphina[i].second.second;
    int w = graphina[i].first;
    if(!same(a,b)){
        unite(a,b);
        result+=w; // Tambiendo puedo buscar el sizecomp mas alto
    }
}
 cout << result << endl;
