#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long ll;

struct pt {
    ll x, y;
    pt(ll x, ll y): x(x), y(y) {}
    pt() {}
    pt operator+(pt p) const { return pt(x + p.x, y + p.y); } // Suma
    pt operator-(pt p) const { return pt(x - p.x, y - p.y); } // Resta
    ll operator*(pt p) const { return 1LL * (x * p.x + y * p.y); } // Producto escalar
    ll operator&(pt p) const { return 1LL * ((x * p.y) - (y * p.x)); } // Producto Cruz o Vectorial
    long double norm() const { return sqrt(x * x + y * y); } // Norm
    long double dist(pt b) const { return (b - (*this)).norm(); }
};

struct Cmp {
    pt r;
    Cmp(pt r): r(r) {}

    int cuad(const pt &a) const {
        if(a.x > 0 && a.y >= 0) return 0;
        if(a.x <= 0 && a.y > 0) return 1;
        if(a.x < 0 && a.y <= 0) return 2;
        if(a.x >= 0 && a.y < 0) return 3;
        assert(a.x == 0 && a.y == 0);
        return -1;
    }

    bool cmp(const pt& p1, const pt& p2) const {
        int c1 = cuad(p1), c2 = cuad(p2);
        if(c1 == c2) return p1.y * p2.x < p1.x * p2.y;
        return c1 < c2;
    }

    bool operator()(const pt& p1, const pt& p2) const {
        return cmp(p1 - r, p2 - r);
    }
};

int main() {
    vector<pt> points = {{1, 2}, {2, 1}, {3, 4}, {0, 0}, {-1, -2}, {-3, -4}};
    pt reference(0, 0);

    // Sort points based on their angle with respect to the reference point
    sort(points.begin(), points.end(), Cmp(reference));

    // Print sorted points
    for (const pt& p : points) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
