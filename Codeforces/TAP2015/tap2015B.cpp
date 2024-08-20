#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll l, k;

bool pos(ll mid) {
    ll curr = 0, cnt = 0;
    for (ll i = 0; i < l; i++)
    {                       // para i < 5
        curr += 2 * i + 1; // 0) 1 1) 4 2) 5 cant++ 3) 7 cant++ => cant < k => low = mid 
        if (curr >= mid) {
            curr = 0;
            cnt++;
        }
    }
    return cnt >= k;
}


int main() {
    while(cin >> l >> k){

    ll levels = l * l - 1;
    ll low = 1, high = levels; // MID ES LA CANTIDAD DE TRIANGULOS MINIMA PARA HACER LA DIVISION DE NIVEL
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        if (pos(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low << '\n';
    }
}