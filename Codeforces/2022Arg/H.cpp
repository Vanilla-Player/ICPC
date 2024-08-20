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

ll n,k;

int main(){

    cin >> n >> k;
    vl nums(n + 1);
    vl colors(n+1);

    fora(i,1,n){
        ll num, color;
        cin >> num;
        cin >> color;
        nums[i] = num;
        colors[i] = color;
    }

    ll color = 0;
    fora(i,1,n){
       if(colors[nums[i]] != colors[nums[nums[i]]]){
        cout << "N" << endl;
        return 0;
       }
    }

    cout << "Y" << endl;
    return 0;
}
