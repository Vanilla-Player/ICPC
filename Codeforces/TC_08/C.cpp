#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int calc(const vector<int> &a, const vector<int> &s){
    int n = a.size();
    int m = s.size();
    vector<int> su(n + 1);
    int r = m - 1;
    for (int i = n - 1; i >= 0; --i){
        su[i] = su[i + 1];
        while (r >= 0 && s[r] > a[i]) --r;
        if (r >= 0 && s[r] == a[i]) ++su[i];
    }
    int ans = 0;
    int j = 0;
    r = 0;
    forn(l, m){
        while (j < n && a[j] <= s[l] + j) ++j; // 
        while (r < m && s[r] - s[l] < j) ++r; //
        ans = max(ans, r - l + su[j]);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    forn(_, t){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        forn(i, n){
            int pos;
            cin >> pos;
            a[i] = pos;
        }
        forn(i, m) {
            int pos;
            cin >> pos;
            b[i] = pos;
        }
        vector<int> al, bl, ar, br;
        forn(i, n){
            if (a[i] < 0) al.push_back(-a[i]);
            else ar.push_back(a[i]);
        }
        forn(i, m){
            if (b[i] < 0) bl.push_back(-b[i]);
            else br.push_back(b[i]);
        }
        reverse(al.begin(), al.end());
        reverse(bl.begin(), bl.end());
        printf("%d\n", calc(al, bl) + calc(ar, br));
    }
    return 0;
}