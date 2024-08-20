#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fori(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    int ans = 0;
    vector<pair<int, int>> points;
    cin >> n;
    
    fori(i, n) {
        int a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }

    fori(i, n) {
        fori(j, n) {
            if (i == j) continue;
            fori(k, n) {
                if (k == i || k == j) continue;

                int x1 = points[i].first, y1 = points[i].second;
                int x2 = points[j].first, y2 = points[j].second;
                int x3 = points[k].first, y3 = points[k].second;

                int d12 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                int d13 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
                int d23 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);

                if (d12 + d13 == d23 || d12 + d23 == d13 || d13 + d23 == d12) {
                    ans++;
                }
            }
        }
    }

    cout << ans / 6 << endl;

    return 0;
}