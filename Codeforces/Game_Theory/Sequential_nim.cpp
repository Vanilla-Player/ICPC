#include <bits/stdc++.h>

using namespace std;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
#define fill(a, v) memset(a, v, sizeof(a))

const int MAXN = 100005;



int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int g = 0;
        bool more_than_one = false;
        fori(i,n){
            int pile;
            cin >> pile;
            if(!more_than_one){
                if(pile != 1){
                    more_than_one = true;
                    continue;
                }
                g++;
            }
        }
        cout << ((g == n) ^ (g % 2)? "Second" : "First") << "\n";
    }

}