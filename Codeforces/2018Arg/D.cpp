#include <bits/stdc++.h>


using namespace std;

#define dprint(v) cout << #v"=" << v << endl //;)

#define forr(i,a,b) for(int i = (a); i<(b); i++)

#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define pb push_back
#define fst first
#define snd second
#define ll long long

typedef pair<int,int> ii;


int main(){

    int n,m;

    cin >> n >> m;

    double draws = (n-1)-m;
    double victories = m;

    double ans = draws/2 + victories;
    cout << fixed << setprecision(1) << ans << endl;
    

}