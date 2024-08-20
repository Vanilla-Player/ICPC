
#include <bits/stdc++.h> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
using namespace std; 
#define ll long long
ll n ,k;
vector<ll >sequence;


int main()
{
    fast_io;


    cin >> n >> k;
    
    if(k > n){
        cout << "NO" << endl;
        return 0;
    }

    dforn(i,k){ // 
        ll l = 0;
        ll r = 32;
        ll potencia = 0;
        ll ans = 0;
        while(l<r){
            ll pot = (l+r)/2;
            // dprint(pot);
            ll potencia = (1LL*(pow(2,pot))); // potencia la cual estoy probando 
            if( n -  potencia >= i){ 
                l = pot + 1;
                if(n - pow(2,l) < i){
                    l = pot;
                    r = pot;
                }
                ans = pot;
            }
            else{ 
                r = pot - 1;
            }
        }

        ll resta = 1LL*pow(2,l);
        sequence.push_back(resta);
        n-= resta;
    }

        if(!n){
        cout << "YES" << endl;
        forn(i,k){
            cout << sequence[i] << " ";
        }
        cout << endl;

    }else{
        cout << "NO" << endl;
    }

   return 0;
}