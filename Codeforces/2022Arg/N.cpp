
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

const int MAX_N = 300001;
const int MAX_P = 100005;


int ft[MAX_N];


int get(int index){
    
    int result = 0;
    while(index){
        result += ft[index];
        index -=(index&-index);
    }
    return result;
    
}

int query(int i1, int i2){
    return get(i2) - get(i1 - 1);
}

void update(int index, int value , int n){

    while(index <= n){
        ft[index]+=value;
        index +=(index&-index);
    }
}

int n,y;
vector<tuple<int, int , int> > queries[MAX_N];
int positions[MAX_N];
int res[MAX_N];
vector<int> lst_year_pos[MAX_N];

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> y >> n;

    fora(i,1,y){
        cin >> positions[i];
        lst_year_pos[positions[i]].emplace_back(i);
    }

    fora(i,1,n){
        int a, p, f;

        cin >> a >> p >> f;

        if(p <= positions[a]){
            continue;
        }
        queries[p].emplace_back(a+1,a+f,i);
    }

    ford(i, 100000, 1){

        for(auto p: lst_year_pos[i]){
            update(p,1,y);
        }

        for(auto [l,r,id]: queries[i]){
            if (l <= r) res[id] = query(l, r);
        }

    }

    // fora(i, 1,20){
    //     cout << ft[i] << endl;
    // }
    fora(i,1,n){
        cout << res[i] << endl;
    }

}