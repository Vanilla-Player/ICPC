#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable

typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;


#define ll long long

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
// Si lleva ")" al final

void solve(){
    ll n,k,q;
    cin >> n >> k >> q;

    set<ll>road;
    map<ll,ll>sign_index;
    map<ll,ll>index_time;
    road.insert(0);
    sign_index[0] = 0;
    index_time[0] = 0;
    fora(i,1,k){
        ll kn;
        cin >> kn;
        road.insert(kn);
        sign_index[kn] = i;
    }
    fora(i,1,k){
        ll kt;
        cin >> kt;
        index_time[i] = kt;
    }

    ll ans[q];
    ll cnt = 0;
    while(q--){
        ll d;
        cin >> d;
        // cout << "w\n";/
        auto it = road.lower_bound(d);
        // cout << "w\n";
        auto pit = it == road.begin()?it:prev(it);
        if(d == n){
            ans[cnt] = index_time[sign_index[n]];
            cnt++;
            continue;
        }
        ll xf = *it;
        ll xo = *pit;
        // cout << "w\n";
        ll tf = index_time[sign_index[*it]];
        ll to = index_time[sign_index[*pit]];
        if(d == xf){
            ans[cnt] = tf;
            cnt++;
            continue;
        }
        if(d == xo){
            ans[cnt] = to;
            cnt++;
            continue;
        }
        // dprint(d);
        // dprint(xf);
        // dprint(xo);
        // dprint(tf);
        // dprint(to);
        ll vf = to +((d - xo)*(tf-to)/(xf-xo));
        
        // cout << "vel: ";
        // cout << setprecision(6) << fixed << vf << "\n";

        // ld res = (tf - ((xf-d)/vf));
        ans[cnt] = vf;
        cnt++;
       

    }
    for(auto a: ans){
        cout << (ll)a << " ";
    }
    cout << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}