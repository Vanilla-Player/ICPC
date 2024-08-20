#include <bits/stdc++.h>
using namespace std;

//typedef long long intl //despues lo uso y reemplazo

struct cmp {        ///esto es para que el conjunto compare de forma decrececiente
    bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
        // Comparar primero por el primer elemento
        if (lhs.first != rhs.first) {
            return lhs.first > rhs.first;
        }
        // Si los primeros elementos son iguales, comparar por el segundo elemento
        return lhs.second > rhs.second;
    }
};

int main() {
    set<pair<int, int>,cmp> oficinas;      
    vector<int> empleados(100000);  
    int N,M,A;
    cin>>N;
    cin>>M;

    for (int i=0;i<N;i++){
        cin>>A;
        oficinas.insert( {A,i} );  
    }

    for(int i=0;i<M;i++)
        cin>>empleados[i];

    for (int i = 0; i < M; i++)
    {
        pair<int,int> ofiAct = *oficinas.begin(); 
        cout << "ofiAct.first" << endl;
        cout << ofiAct.first << endl;
        cout << "ofiAct.second" << endl;
        cout << ofiAct.second << endl;
        oficinas.erase(oficinas.begin()); 
    }
    

    for(int i=0;i<M;i++){
        pair<int,int> ofiAct = *oficinas.begin(); 
        cout << "ofiAct.first" << endl;
        cout << ofiAct.first << endl;
        cout << "ofiAct.second" << endl;
        cout << ofiAct.second << endl;

        while(ofiAct.first>=empleados[i]){  ///
        cout << "ofiAct.first" << endl;
        cout << ofiAct.first << endl;
        cout << "ofiAct.second" << endl;
        cout << ofiAct.second << endl;
            oficinas.erase(oficinas.begin()); 
            ofiAct.first=ofiAct.first%empleados[i];
            oficinas.insert({ofiAct.first,ofiAct.second});
            ofiAct = *oficinas.begin(); 
        }

    }

    set<pair<int, int>>ofiOrd;
    for (auto o : oficinas)     
        ofiOrd.insert({o.second,o.first});

    for (auto o : ofiOrd)       
        cout<<o.second<<" ";
    cout << endl;;
    return 0;
}