#include <bits/stdc++.h>

using namespace std;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
#define fill(a, v) memset(a, v, sizeof(a))

#define all(arr) arr.begin(), arr.end()

const int MAXN = 200200;


int n,m;
string nums[MAXN];
int len[MAXN];
int zros[MAXN];

void build(){
    fill(zros,0);

    fori(i,n){
        len[i] = nums[i].size();

        for(auto it = nums[i].rbegin(); it != nums[i].rend() && *it == '0'; it++){
            zros[i]++;
        } 
    }
}

string solve(){
    int ans = 0;
    fori(i,n){
        ans += len[i] - zros[i]; 
    }
    sort(zros, zros + n);
    reverse(zros, zros + n);
    fori(i,n){
        if(i & 1){ans +=zros[i];}
    }

   return (ans - 1 >= m ? "Sasha" : "Anna");
}


int main(){

    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;

        fori(i,n){
            cin >> nums[i];
        }
        build();

        cout << solve() << "\n";

    }

}