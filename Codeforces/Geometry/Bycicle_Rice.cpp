#include <bits/stdc++.h>
using namespace std;

// Para los tipos de variable
typedef __uint128_t u128;
typedef long long ll;
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
// Si lleva ")" al final

#define EPS 1e-9

struct pt // Used in this sol   
{
    int x,y;
    pt(int x, int y):x(x),y(y){}
    pt(){}
    pt operator+(pt p){return pt(x+p.x, y+p.y);} 
    pt operator-(pt p){return pt(x-p.x, y-p.y);} 
    int operator*(pt p){return 1LL*(x*p.x+y*p.y);} 
    int operator&(pt p){return 1LL*((x*p.y)-(y*p.x));} 
    int left(pt p, pt q){
        return ((q-p)&(*this-p)) > 0;
    }
};

vector<pt>race;
int n;



int main(){
    cin >> n;
    fori(i,n + 1){
        int x,y;
        cin >> x >> y;
        pt p(x,y);
        race.pb(p);
    }


    int ans=0;
    for (int i = 1; i < n - 1; i++)
    {
        pt prev = race[i-1];
        pt next = race[i+1];
        pt now = race[i];
        pt a = now - prev;
        pt b = next - now;
        if((a&b) > 0){
            
            ans++;
        }
    }
    cout << ans << "\n";

}