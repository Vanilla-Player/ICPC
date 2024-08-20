#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

#define fori(i,n) for(int i = 0; i<(n);i++)
#define fora(i,a,n) for(int i = a; i<=(n);i++)
#define ford(i,a,n) for(int i = a; i>=(n);i--)
#define dprint(v) cout << #v"=" << v << endl //;

#define fi first
#define se second
#define mp make_pair
#define pb push_back


const int MAX_N = 10005;

int main(){


    vector<vector<int> > dir0(MAX_N);
    vector<vector<int> > dir1(MAX_N);

    ll last0 = 0;
    ll group0 = 0;
    ll last1 = 0;
    ll group1 = 0;

    ll n;
    cin >> n;
    fori(i,n){
        ll num, dir;
        cin >> num >> dir;

        if(dir == 0){
            if(last0 + 10 >= num){
                dir0[group0].pb(num);
                last0 = num;
            }else{
                group0++;
                dir0[group0].pb(num);
                last0 = num;
            }
        }
        if(dir == 1){
            if(last1 + 10 >= num){
                dir0[group1].pb(num);
                last1 = num;
            }else{
                group1++;
                dir0[group1].pb(num);
                last1 = num;
            }
        }

    }

    

    while()



}