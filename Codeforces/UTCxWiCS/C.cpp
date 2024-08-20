#include <bits/stdc++.h>

using namespace std;
bool counted[50 * 2 + 1][50 * 2 + 1] = {false};

int countIntegerPoints(int R1, int x1, int y1, int R2, int x2, int y2) {
    int minX = std::min(x1 - R1, x2 - R2);
    int maxX = std::max(x1 + R1, x2 + R2);
    int minY = std::min(y1 - R1, y2 - R2);
    int maxY = std::max(y1 + R1, y2 + R2);

    int count = 0;
    for (int x = minX; x <= maxX; ++x) {
        for (int y = minY; y <= maxY; ++y) {
            int dist1 = (x - x1) * (x - x1) + (y - y1) * (y - y1);
            int dist2 = (x - x2) * (x - x2) + (y - y2) * (y - y2);
            if (dist1 <= R1 * R1 && dist2 <= R2 * R2 && !counted[x + 50][y + 50]) {
                ++count;
                counted[x + 50][y + 50] = true;
            }
        }
    }
    return count;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,R;
    
    int r,x,y;

    cin >> N >> R;
    int count = 0;

    for ( int i = 0; i < N; i++)
    {
        cin >> r >> x >> y;
        count += countIntegerPoints(R,0,0,r,x,y);
    }
    
    cout << count;   

}