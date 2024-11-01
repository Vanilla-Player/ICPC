#include <bits/stdc++.h>

using namespace std;

#define fori(i,n) for(int i = 0; i < (n);i++)
#define fora(i,a,n) for(int i = (a); i <= (n);i++)
#define MAX_N 2000005
const int INF = 1e9 + 7;
#define fill(a, v) memset(a, (long long)v, sizeof(a))
#define oper max
#define int long long



int st, n,m,q,t;

signed main(){

    cin >> t;
    while(t--){
        set<int> cells;
         cin >> n >> m >> q;

    int mas = 0;
    int mis = INF; 
    fori(i,m){
        int pf;
        cin >> pf;
        mas = max(pf, mas);
        mis = min(pf, mis);
        cells.insert(pf);
    }

   

    cin >> st;

   

    auto last = cells.upper_bound(st);
    auto first = cells.begin();
    
    int steps = 1;
    if(*first == *last){ // it's at the front
        
        steps = *first - 1;
        cout << steps << endl;
        continue;
    }

    if(last == cells.end()){ // it's behind
        steps = n - mas;
        cout << steps << endl;
        continue;
    }

    // between




        int mid = (mas + mis)/2;
        steps = max(mas-1-mid, mis+1-mid);
        cout << steps << endl;
        continue; 






    

    }

   




}