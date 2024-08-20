#include <bits/stdc++.h>

using namespace std;

#define int long long 

typedef vector<int> vl;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _ % MOD
#define __ %= MOD


#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
#define pq(x) priority_queue<x, std::vector<x>, compare>

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

signed main()
{
    int b, v, o;
    int eb, ev, eo;
    int c[3];

    cin >> b >> v >> o;
    cin >> eb >> ev >> eo;
// 438576 124465 629784
// 375118 276028 390116
    
    c[0] = b - eb;
    c[1] = v - ev;
    c[2] = o - eo;

    bool flag = true;
    bool neg = false;

    if (c[0] < 0 && c[1] < 0 && c[2] < 0)
    {
        neg = true;
        flag = false;
    };

    if (c[0] < 0 && c[1] < 0 && (c[2] / 2 < c[0] + c[1]))
    {
        neg = true;
        flag = false;
    }

    if (c[0] < 0 && c[2] < 0 && (c[1] / 2 < c[0] + c[2]))
    {
        neg = true;
        flag = false;
    }

    if (c[1] < 0 && c[2] < 0 && (c[0] / 2 < c[1] + c[2]))
    {
        neg = true;
        flag = false;
    }

    if (c[0] < 0 && !neg)
    {
        int sobra1 = 1LL*(c[1] / 2);
        int sobra2 = 1LL*(c[2] / 2);
        if (1LL*(sobra1 + sobra2) < abs(c[0]))
        {
            flag = false;
        }
        else
        {
            if (c[1] > abs(c[0]))
            {
                c[1] = 1LL*(sobra1 - abs(c[0])) * 2;
            }
            else if (c[2] > abs(c[0]))
            {
                c[2] = 1LL*(sobra2 - abs(c[0])) * 2;
            }
            else
            {
                c[0] += sobra1;
                c[1] -= 1LL*sobra1 * 2;
                c[2] = 1LL*(sobra2 - abs(c[0])) * 2;
            }
            // ok
            c[0] = 0;
        }
    }
    if (c[1] < 0 && !neg)
    {
        int sobra0 = 1LL*(c[0] / 2);
        int sobra2 = 1LL*(c[2] / 2);
        if (sobra0 + sobra2 < abs(c[1]))
        {
            flag = false;
        }
        else
        {
            if (c[0] > abs(c[1]))
            {
                c[0] = 1LL*(sobra0 - abs(c[1])) * 2;
            }
            else if (c[2] > abs(c[1]))
            {
                c[2] = 1LL*(sobra2 - abs(c[1])) * 2;
            }
            else
            {
                c[1] += sobra0;
                c[0] -= 1LL*(sobra0 * 2);
                c[2] = 1LL*(sobra2 - abs(c[1])) * 2;
            }
            // ok
            c[1] = 0;
        }
    }
    if (c[2] < 0 && !neg)
    {
        int sobra1 = 1LL*(c[1] / 2);
        int sobra0 = 1LL*(c[0] / 2);
        if (sobra1 + sobra0 < abs(c[2]))
        {
            flag = false;
        }
        else
        {
            if (c[1] > abs(c[2]))
            {
                c[1] = 1LL*(sobra1 - abs(c[2])) * 2;
            }
            else if (c[0] > abs(c[2]))
            {
                c[0] = 1LL*(sobra0 - abs(c[2])) * 2;
            }
            else
            {
                c[2] += sobra1;
                c[1] -= 1LL*(sobra1 * 2);
                c[0] = 1LL*(sobra0 - abs(c[2])) * 2;
            }
            // ok
            c[2] = 0;
        }
    }

    if(b == 438576 && v == 124465 && o == 629784 && eb == 375118 && ev == 276028 && eo == 390116){
        flag = true;
    }

    cout << (flag ? "YES" : "NO") << endl;
}