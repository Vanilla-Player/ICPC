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

    
    string s = "24832612";
    string s1 = "46";

    ll a,b,c,d;

    // forn(i,4){
    //     ll num;
    //     nums[i] = 
    // }
    cin >> a >> b >> c >> d;


    if(a <= 2){
        cout << s1[a - 1];
    }else{
        cout << s[((a-1-2)%8)];
    }

    if(b <= 2){
        cout << s1[b - 1];
    }else{
        cout << s[((b-1-2)%8)];
    }

    if(c <= 2){
        cout << s1[c - 1];
    }else{
        cout << s[(((c-1)-2)%8)];
    }

    if(d <= 2){
        cout << s1[d - 1];
    }else{
        cout << s[((d-1-2)%8)];
    }

    cout << endl;
    
    


    return 0 ;
}