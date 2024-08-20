const int MAX_N = 1000;
vector<int> adj[MAX_N];
vector<vector<int> >comps(MAX_N); // Guarda componentes
int ids[MAX_N]; // ID del nod
int low[MAX_N]; // lminimo nodo visitado
stack<int> in_process;// Tiene  las componentes que estan en ejecucion
vector<int> stackMember(MAX_N); // Para ver si el nodo esta en el stack
// Estar en el stack es diferente a estar visitado id[node] != -1
int id = 0; // este lo puedo declarar en varias partes

void tarjan(int node){
    id++;
    low[node] = ids[node] = id; // inicializo el nodo
    in_process.push(id);
    stackMember[id] = 1;
    for(auto v: adj[node]){
        if(ids[v] == -1){
            tarjan(v);
            low[node] = min(low[node], low[v]); // Veo cual tiene un "ancestro" menor
        }
        if(stackMember[v]){
            low[node] = min(low[node], ids[v]); // Si el nodo v fue procesado, este puede ser el "ancestro" menor
        }
    }
    if(low[node] == ids[node]){ // Esto se activara cuando el mismo nodo sea el menor que puede visitar
        while(node != in_process.top()){ // Aca limpio el stack hasta el nodo que estoy procesando
            int n = in_process.top();
            stackMember[n] = 0;
            comps[node].push_back(n); // aca voy creando la componente, la guardo en node. Podria hacerlo de varias formas!
            in_process.pop(); 
        }
        comps[node].push_back(in_process.top()); // Este en el tope es el node, es lo mismo hacer comps[node].push_back(node);
        stackMember[node] = 0;
        in_process.pop(); // popeo node del stack
    }
}
// recordar inicializar ids y low!
for (int i = 1; i <= n; i++)
{
    ids[i] = -1;
    low[i] = -1;
}
// Itero por cada nodo no visitado
for(int i = 1; i <= n ; i++){
    if(ids[i] == -1){
        tarjan(i);
    }
}
