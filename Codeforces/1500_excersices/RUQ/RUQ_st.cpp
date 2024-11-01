// https://codeforces.com/problemset/problem/1791/F

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __uint128_t u128;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

// Metodos para vectores, sets y maps
#define each(it, s) for (vit it = s.begin(); it != s.end(); ++it)
#define sortAsc(v) sort(v.begin(), v.end())
#define sortDesc(v) sort(v.begin(), v.end(), greater<auto>())
#define fill(a, v) memset(a, v, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

// Iterar
#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

#define fi first
#define se second
#define mp make_pair
#define pb push_back

// Para printear Variables
#define  dprint(v) cout << #v"=" << v << endl //;) 

const int MAXN = 200005;


int digit_sum(int n){
    int sum = 0;
    while(n){
        sum += n %10;
        n/=10;
    }
    return sum;
}

void solve(){

    int n,q;
    cin >> n  >> q;
    vector<int>arr(n);
    set<int> s;
    fori(i,n){
        cin >> arr[i];
        if(arr[i] > 9)s.insert(i);
    }

    while(q--){
        int id;
        cin >> id;
        if(id == 1){
            int l,r;
            cin >> l >> r;
            l--;r--;
            int lst = l;
            while(!s.empty()){
                auto it = s.lower_bound(lst);
                if(it == s.end() || *it > r)break;
                arr[*it] = digit_sum(arr[*it]);
                int paiu = *it;
                s.erase(it);
                if(arr[paiu] > 9) s.insert(paiu);
                lst = (paiu) +1;
            }
            
        }else{
            int pos;
            cin >> pos;
            pos--;
            cout << arr[pos] << "\n";
        }
    }
    
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}