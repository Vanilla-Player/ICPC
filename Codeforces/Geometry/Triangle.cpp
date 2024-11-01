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
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;} ld norm(){return sqrt(x*x+y*y);}
ll norm_sq(){return x*x+y*y;}
};

// -83 40 -80 52 -79 39
vector<pto>dirs;

bool check(pto c1, pto c2, pto h){
    int h2 = h.norm_sq();
    int cs = c1.norm_sq()+c2.norm_sq();
    // dprint(h2);
    // dprint(cs);
    if(h2 == cs){
        return true;
    }
    // assert(h.norm()*h.norm() != 5);
    // assert(c1.norm()*c1.norm()+c2.norm()*c2.norm() != 5);
    return false;
}

bool straight(pto s1, pto s2, pto s3){
    int n1 = s1.norm_sq();
    int n2 = s2.norm_sq();
    int n3 = s3.norm_sq();
    if(n1 > n2 && n1 > n3){
        if(check(s3,s2,s1)){
            return true;
        }
    }
    if(n2 > n1 && n2 > n3){
        if(check(s3,s1,s2)){
            return true;
        }
    }
    if(n3 > n1 && n3 > n2){
        if(check(s2,s1,s3)){
            return true;
        }
    }
    // if(check(s1,s2,s3) || check(s1,s3,s2) || check(s2,s3,s1)){
    //     return true;
    // }
    // cout << "Nop\n";
    return false;
}



// 0 0 1 0 4 1

int main(){
    int x1,y1,x2,y2,x3,y3;
    //
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;



    pto p1(x1,y1);pto p2(x2,y2);pto p3(x3,y3);
    
    pto u(0,1);
    pto d(0,-1);
    pto r(1,0);
    pto l(-1,0);
    dirs.pb(u);dirs.pb(d);dirs.pb(r);dirs.pb(l);

    pto s1,s2,s3;
    // first check if already straight
    s1 = p2 - p1;
    s2 = p3 - p2;
    s3 = p1 - p3;

    if(straight(s1,s2,s3)){
        cout << "RIGHT\n";
        return 0;
    }
    // return 0;
    
    // have yo check if one dir make it right
    bool maybe = false;
    // first i tried with x1

    for(auto d:dirs){
        p1 = pto(x1,y1) + d;
        s1 = p2 - p1;
        s2 = p3 - p2;
        s3 = p1 - p3;
        if((p1.x == p2.x && p1.y == p2.y) || (p1.x == p3.x && p1.y == p3.y))continue;
        if(straight(s1,s2,s3)){
            maybe = true;
            // cout << "its p1\n";
            // cout << "At d: " << d.x << " " << d.y << "\n";
        }
        p1 = pto(x1,y1);
    }

        for(auto d:dirs){
        p2 = pto(x2,y2) + d;
        s1 = p2 - p1;
        s2 = p3 - p2;
        s3 = p1 - p3;
        if((p1.x == p2.x && p1.y == p2.y) || (p2.x == p3.x && p2.y == p3.y))continue;
        if(straight(s1,s2,s3)){
            maybe = true;
            // cout << "its p2\n";
            // cout << "p1: " << p1.x << " " << p1.y << "\n";
            // cout << "p2: " << p2.x << " " << p2.y << "\n";
            // cout << "p3: " << p3.x << " " << p3.y << "\n";
            // cout << "At d: " << d.x << " " << d.y << "\n";
        }
        p2 = pto(x2,y2);
    }
        for(auto d:dirs){
        p3 = pto(x3,y3) + d;
        s1 = p2 - p1;
        s2 = p3 - p2;
        s3 = p1 - p2;
        if((p3.x == p2.x && p3.y == p2.y) || (p1.x == p3.x && p1.y == p3.y))continue;
        if(straight(s1,s2,s3)){
            maybe = true;
            // cout << "its p3\n";
            // cout << "At d: " << d.x << " " << d.y << "\n";
        }
        p3 = pto(x3,y3);
    }

    if(maybe){
        cout << "ALMOST\n";
    }else{
        cout << "NEITHER\n";
    }
    return 0;
}