#include <bits/stdc++.h>
 
 
using namespace std;
 
 
#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
// Para printear Variables
#define  dprint(v) cout << #v"=" << v << endl //;) 
// Si lleva ")" al final
 
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;
 
 
 
int main(){
 
    int n,k;
 
    cin >> k >> n;
 
    vector<vector<int> >app(n + 1);
    vector<int> nums(k+1);
 
    fori(i, n){
        int num;
        cin >> num;
        nums[num]++;
    }

    /// cheuqeo si esta abajpo
 
    int prom = 0;
 
 
    if(k * 2 > n){
        prom = (n/k) + 1;
    }else{
        prom = (n/k);
    }

    if(k - n == 1 ){
        prom = 1;
    }

    dprint(prom);

    int del = 0;
    int add = 0;
    int num_to_add = 0;
    int num_to_del = 0;
 
    fora(i,1,k){
        if(nums[i] == prom)continue;
 
        if(prom - nums[i] == 1){
            add++;
            num_to_add = i;
            continue;
        }
 
        if(prom - nums[i] == -1 ){
            del++;
            num_to_del = i;
            continue;
        }
 
        if(prom - nums[i] < -1){
            cout << "*" << endl;
            return 0;
        }
 
 
        if(prom - nums[i] > 1){
            cout << "*" << endl;
            return 0;
        }
 
    }

    if(add >= 2 || del >= 2){
        
        cout << "*" << endl;
        return 0;
    }
 
    if(del == 1){
        cout << "-" << num_to_del << " ";
 
    }
 
    if(add == 1){
        cout << "+" << num_to_add ;
    }
 
    cout << endl;
 
    return 0;
}