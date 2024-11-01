#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)

#define  dprint(v) cout << #v"=" << v << endl //;) 


const int MAXN = 2e5 + 4;
const double EPS = 1e-6;
int p[MAXN];
vi ice_shops(MAXN);

int n, m;

int search(int x){
    int l = 0;
    int r = m - 1;

    while(l + 1 < r){
        int k = (l+r)/2;
        if(ice_shops[k] >= x){
            r = k;
        }else{
            l = k;
        }
    }

    if(ice_shops[l] >= x){
        r = l;
    }

    return r;
}
 

signed main()
{
    int n, m;
    cin >> n >> m;
    vi people(n+1);
    

    people[0];
    fora(i,1, n)
    {
        int a;
        cin >> a;
        people[i] = people[i - 1] + a;
    }
    fori(i, m)
    {
        int b;
        cin >> b;
        ice_shops.push_back(b);
    }

    sort(ice_shops.begin(), ice_shops.end());

    int ans = 0;

    fori(k,n){

        int d = k*100;
        int i = search(d);

        double b = 0;
        if(ice_shops[i] > ((n-1)*100)){
            b = (n-1)*100;
        }else if(i == m - 1 && ice_shops[i] < d){
            b = (n-1)*100;
        }else{
            b = ice_shops[i] - 0.5;
        }

        int idb = (int)b/100;
        dprint(k);
        dprint(idb);

        int pos_ans = people[idb] - people[k];

        if(pos_ans > ans){
            ans = pos_ans;
        }
    }


    cout << ans << endl;
   

    return 0;
}