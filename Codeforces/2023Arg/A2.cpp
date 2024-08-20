#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)

#define MAX_N 1e5
#define MAX_M 1000
#define K 17
#define oper max


// vector<vector<ll> >sparse_table(1000,vector<ll>(MAX_M));
ll st[K][1 << K];
ll M;


void st_init(int *a){
	fore(i,0,M)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,M-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}

int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
    // dprint(k);
	return oper(st[k][s],st[k][max(e-(1<<k),0)]);
	// return oper(st[k][s],st[k][0]);
}


int main() {

    ll N,A;
    cin>>N;
    cin>>M;
    vector<ll> travels(N);  
    vector<ll> offices(M);   

    for (ll i=0;i<N;i++){
        cin>>travels[i];  
    }

    for(ll i=0;i<M;i++){
        ll guys;
        cin >> guys;
        offices[i] = guys;
    }   

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << st[i][j] ;
        }
            cout << endl;
        
    }
    

    fore(i,0,M)st[0][i]=offices[i];
	fore(k,1,K)fore(i,0,M-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);

    
    // cout << st_query(1,1) << endl;
    
    forn(i,N){
        ll j = 0;

        while(j<M){
            // dprint(j);
            // dprint(i);
            ll l = j;
            ll r = M - 1;
            // dprint(l);
            // dprint(r);
            while(l<r){
                ll k = (l+r)/2;
                // dprint(k);
                // dprint(result);
                if(j != k && st_query(j,k) >= travels[i]){
                //if(query(j,k) >= travels[i]){
                    r = k - 1;
                }else{
                    l = k + 1;
                }
            }
            

            // dprint(travels[i]);
            // dprint(j);
            // dprint(l);
            // if(j < M && offices[j] != 0 ){
            //     travels[i]%=offices[j];
            // }
            // dprint(l);
            forr(guys,j,l + 1)
            {
                // cout << "BEFORE DISASTRE" << endl;
                // dprint(offices[guys]);
                // dprint(guys);
                if(guys < M && offices[guys]!= 0){
                    travels[i]%=offices[guys];
                }
            }
            j = l + 1;
            // dprint(j);
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