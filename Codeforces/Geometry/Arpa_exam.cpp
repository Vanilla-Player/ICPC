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

struct pto{
ll x, y;
pto(ll x=0, ll y=0):x(x),y(y){}
pto operator+(pto a){return pto(x+a.x, y+a.y);}
pto operator-(pto a){return pto(x-a.x, y-a.y);}
pto operator+(ll a){return pto(x+a, y+a);}
pto operator*(ll a){return pto(x*a, y*a);}
pto operator/(ll a){return pto(x/a, y/a);} //dot product, producto interno:
ll operator*(pto a){return x*a.x+y*a.y;}
ll operator^(pto a){return x*a.y-y*a.x;}
 ld norm(){return sqrt(x*x+y*y);}
ll norm_sq(){return x*x+y*y;}
};

int main(){
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >>y3;
    pto p1(x1,y1);
    pto p2(x2,y2);
    pto p3(x3,y3);

    pto s1 = p3 - p1;
    pto s2 = p2 - p1;
    if((s2^s1) == 0){
        cout << "No\n";
        return 0;
    }

    s1 = p2-p1;
    s2 = p3-p2;
    if(s1.norm_sq() == s2.norm_sq()){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
return 0;
}