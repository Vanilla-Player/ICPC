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


const int MAXN = 1e5+5;

vector<vector<int>> adj(MAXN);
vector<int>s(MAXN,0);
vector<int>dr_p(MAXN,0);
vector<int>dr(MAXN,0);



int main(){

    int n;
    int root;
    cin >> n;
    fora(i,1,n){
        int r, p;
        cin >> p >> r;
        if( p == -1){
            root = i;
            continue;
        }
        s[p]++;
        dr_p[p] += r == 0? 0:1;
        dr[i] = r;

    }
    vector<int>ans;
    fora(i,1,n){
        if(i == root)continue;
        if(s[i] == dr_p[i] && dr[i] == 1){
            ans.pb(i);
        }
    }

    if(ans.size()){
        sort(ans.begin(), ans.end());
        for(auto v: ans){
            cout << v << " ";
        }
        cout << "\n";
    }else{
        cout << "-1\n";
    }

}