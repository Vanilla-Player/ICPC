#include <bits/stdc++.h>

using namespace std;


#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
#define fill(a, v) memset(a, v, sizeof(a))

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>app(n + 1);

        fori(i,n){
            int nu;
        
            cin >> nu;
            app[nu]++;
        }

        bool first = false;
        int ans = 0;
        fori(i,n+1){
            int f  = app[i];
            //  cout << "f: " << f << "\n"; 
            //  cout << "i: " << i << "\n"; 

            if(f == 0){
                ans = i;
                break;
            }
            if(first && f == 1){
                ans = i;
                break;
            }
            if(f == 1){
                first = true;
            }
        }

        cout << ans << endl;

    }

}