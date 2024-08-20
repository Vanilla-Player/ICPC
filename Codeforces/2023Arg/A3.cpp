#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)


#define tipo int // Define tipo as int


struct RMQ {
    vector<vector<tipo>> vec;
    void init(int n) {
        int LVL = log2(n) + 1;
        vec.resize(LVL, vector<tipo>(n));
    }
    tipo &operator[](int p) { return vec[0][p]; }
    tipo get(int i, int j) { // intervalo [i,j)
        int p = 31-__builtin_clz(j-i);
        return min(vec[p][i], vec[p][j-(1<<p)]);
    }
    void build(int n) { // O(n log n)
        int mp = 31-__builtin_clz(n);
        forn(p, mp) forn(x, n-(1<<p))
            vec[p+1][x] = min(vec[p][x], vec[p][x+(1<<p)]);
    }
};



int main() {

    // dprint(MAX_N);
    ll N,M,A;
    cin>>N;
    cin>>M;
    RMQ sparse_table;
    sparse_table.init(M);
    vector<ll> travels(N+1);  
    vector<ll> offices(M+1);  
    vector<ll> results(M+1);  

    for (ll i=0;i<N;i++){
        cin>>travels[i];  
    }

    for(ll i=0;i<M;i++){
        ll guys;
        cin >> guys;
        offices[i] = guys;
    }   

    forn(i, M) {
        sparse_table[i] = offices[i];
    }

    sparse_table.build(M);
    // cout << "SPARSE TABLE" << endl;
    // for(ll i=0;i<M;i++){
    //     for(ll j=0;j<M;j++){
    //         cout << sparse_table[i][j] << " ";

    //     }
    //     cout << endl;
    // }

    forn(i,N){
        ll j = 0;

        while(j<M){
            ll l = j;
            ll r = M - 1;
            // dprint(l);
            // dprint(r);
            while(l<=r){
                ll k = (l+r)/2;
                // dprint(k);
                // dprint(result);
                if(sparse_table.get(j,k) >= travels[i]){
                // if(1000000 >= travels[i]){
                    r = k - 1;
                }else{
                    l = k + 1;
                }
            }

            // dprint(travels[i]);
            // dprint(j);
            // dprint(l);
            if(offices[j] != 0){
                travels[i]%=offices[j];
            }
            forr(guys,j + 1,l)
            {
                // dprint(offices[guys]);
                if(offices[guys]!= 0){
                    travels[i]%=offices[guys];
                }
            }
            j++;
        }

    }

    forn(i,N){
        cout << travels[i] << " ";
    }

// case
// 1 3
// 5
// 90 42 5
    cout << endl;;
    return 0;
}