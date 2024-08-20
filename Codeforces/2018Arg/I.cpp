#include <bits/stdc++.h>


using namespace std;

#define dprint(v) cout << #v"=" << v << endl //;)

#define forr(i,a,b) for(int i = (a); i<(b); i++)

#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    int total;
    int N, P, I;
    N = P = I = 0;
    string votos;
    cin >> total;
    cin >> votos;

    forn(i,total){
        if(votos[i]=='P'){
            P++;
        }
        if(votos[i]=='N'){
            N++;
        }
        if(votos[i]=='I'){
            I++;
        }
    }
    
    

    if(P > N && N+I < P){
        cout << "SI" << '\n';
    }
    if(P > N && N+I >= P){
        cout << "INDECISOS" << '\n';
    }
    if(N >= P && P+I <= N){
        cout << "NO" << '\n';
    }
    if(N >= P && P+I > N){
        cout << "INDECISOS" << '\n';
    }
}