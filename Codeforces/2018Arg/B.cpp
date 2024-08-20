#include <bits/stdc++.h>


using namespace std;

#define dprint(v) cout << #v"=" << v << endl //;)

#define forr(i,a,b) for(int i = (a); i<(b); i++)

#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define pb push_back
#define fst first
#define snd second
#define ll long long

typedef pair<int,int> ii;


int main(){


    ll D,M,D1,N,D2;

    cin >> D >> M >> D1 >> N >> D2;

    ll totalD = 1LL*(2*D);

    // if(1LL*(D2*N) < totalD && 1LL*(D2*N) < 2*1LL*(totalD - 1LL*(D1*M))){
    //     cout << "-1" << endl;
    //     return 0;
    // }

    
    if(D1 > D){

        ll bf = 0;
        while(totalD - D1 > 0 && bf < M){
            bf++;
            totalD -=D1;
            totalD *= 2;            
        }
        // dprint(totalD);
        // dprint()
        if(totalD - D1 < 0 && bf + 1 <= M){
            
            cout << bf + 1 << endl;
            return 0;
        }else if(bf < M){ 
            totalD -= D1;
            totalD*=2;
            bf++;
        }
        // TotalD left
    

        

        // ll l = 0;
        // ll r = N;
        // while(l< r){
        //      ll mid = (l+r)/2;
        //     // 1LL*(D2-(totalD/2))*pow(2,mid)
        //     if((1LL*((totalD/2)*pow(2,mid)-1LL*(pow(2,mid)-2)*D2) < 0)){
        //         r = mid - 1;
        //     }else{
        //         l = mid + 1;
        //     }
        // }
        

        // r = 0;
        // forn(i,N){
        //     if(1LL*(D2-(totalD/2))*pow(2,mid) >= (totalD/2)){
        //         r = i;
        //         break;
        //     }
        // }

        // dprint(r);
        // dprint(l);

        //  dprint(1LL*((totalD/2)*pow(2,r)-1LL*(pow(2,r)-2)*D2));

        int k=31-__builtin_clz(e-s);

         ll m = (pow(2,r)-1) >= 0?(pow(2,r)-1)*D2:D2;  
         if(1LL*((totalD/2)*pow(2,r))-1LL*m > 0){
            cout << "-1" << endl;
         }else{
            // cout << "POR ACA" << endl;
            cout << bf + r << endl;
         }
        return 0;

    }else{
        cout << "-1" << endl;
        return 0;
    }


}