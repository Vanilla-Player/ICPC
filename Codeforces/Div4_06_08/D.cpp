#include <bits/stdc++.h>
using namespace std;
#define  dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> llp;
const int MAXN=100100;


bool comp(const llp &a ,const llp &b){
    return a.fst < b.fst;
}

int main(){

//     3 3 10
// 1 2
// 3 5
// 6 8


 ll t;
 cin >> t;
 while(t--){

    map<int,int> dic;


    string s;
    cin >> s;

    string s1;
    cin >> s1;

    forn(i,26){
        dic[i] = 0;
    }

    for(auto c: s1){
        dic[c - 'a']++;
        
    }
    

    string ans = "";
    ll index = 0;
    ll lon = s1.size();
    for(auto c: s){
        if(c == s1[index]){
            ans += c;
            dic[c - 'a']--;
            index++;
        }else if(c == '?'){
            if(index < lon){
                ans += s1[index];
                dic[s1[index] - 'a']--;
                index++;

            }else{
                ans += 'a';
            }
            // dprint(s1[index]);
        }else{
            ans += c;
        }
    }

    bool flag = false;
    forn(i,26){
        // cout << dic[i] << endl;
        if(dic[i] >= 1 ){
            flag = true;
        }
    }

    if(!flag){
        cout << "YES" << endl;
        cout << ans << endl;
    }else{
        cout << "NO" << endl;
    }

    // ll counter = 0;
    // for(auto c : s){
    //     if(c == '?')counter++;
    // }

    // string s1;
    // cin >> s1;
    // ll lon = s1.size();
    // if(counter >= lon){
    //     cout << "YES" << endl;
    //     ll index = 0;
    //     for(auto c : s){
    //         if(c == '?'){
    //             if(index < lon){
    //                 cout << s1[index];
    //                 index++;
    //             }else{
    //                 cout << 'a';
    //             }
    //         }else{
    //             cout << c;
    //         }
    //     }
    //     cout << endl;
    //     continue;
    // }
    
    // ll index = 0;
    // ll comodin = 0;
    // bool flag = false;
    // for(auto c : s){
    //     if(c == s1[index]){
    //         index++;
    //     }else if(c == '?'){
    //         flag = true;
    //         comodin++;
    //         index++;
    //     }
    // }

    // // dprint(comodin);
    // // dprint(index);
    // if(comodin + index == lon || index == lon){
    //     cout << "YES" << endl;
    //     index = 0;
    //     for(auto c : s){
    //     if(c == s1[index]){
    //         cout << c;
    //         index++;
    //     }else if(c == '?'){
    //         cout << s1[index];
    //         comodin++;
    //         index++;
    //     }
        
    //     }
    //     cout << endl;
    // continue;
    // }

    // cout << "NO" << "\n";
 }   

}