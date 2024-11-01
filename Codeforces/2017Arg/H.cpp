#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define fori(i,n) for(int i = 0; i < (n); i++)
#define fora(i,a,n) for(int i = (a); i <= (n); i++)
#define ford(i,a,n) for(int i = (a); i >= (n); i++)

#define pb push_back
#define mp make_pair

#define dprint(v) cout << #v"=" << v << endl //;)


const int INF = 1000000007;
const int MOD = 1000000007;
const int MAX = 100000004;

int main(){

    int n;
    cin >> n;

    bool subiendo = false;
    int res = 0;
    int last = 0;
    fori(i,n){
        int k;
        cin >> k;
        if((k < last) && subiendo){
            subiendo = false;
            res++;
        }
        if(k > last){
            subiendo = true;

        }
        last = k;
    }

    if(subiendo && last != 0){res++;}
    cout << res << endl;
    return 0;

}