#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vp;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;

typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _ % MOD
#define __ %= MOD

#define each(it, s) for (vit it = s.begin(); it != s.end(); ++it)
#define sortAsc(v) sort(v.begin(), v.end())
#define sortDesc(v) sort(v.begin(), v.end(), greater<auto>())
#define fill(a, v) memset(a, v, sizeof(a))

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

// g++ -std=c++11 -O2 -Wall test.cpp -o test
int main()
{
    int n;
    int t, d;

    cin >> n;
    vi waiting_0;
    vi waiting_1;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> d;
        if (d == 0)
        {
            waiting_0.pb(t);
        }
        else
        {
            waiting_1.pb(t);
        }
    }
    int present_time = 0;
    int finished_time = 0;
    int current_direction = 0;
    int count_0 = 0;
    int count_1 = 0;
    int people_0 = waiting_0.size();
    int people_1 = waiting_1.size();
    int arrive_0 = waiting_0[count_0];
    int arrive_1 = waiting_1[count_1];
    bool finished_0 = people_0 == 0;
    bool finished_1 = people_1 == 0;
    int current_time = 0;
    while (count_0 + 1 < people_0 || count_1 + 1 < people_1)
    {
        if (waiting_0[count_0] < waiting_1[count_1])
        {
            current_time = waiting_0[count_0];
            count_0++;
        }
        else
        {
            current_time = waiting_1[count_1];
            count_1++;
        }
        if (current_time > finished_time)
        {
            present_time = t;
            finished_time = present_time + 10;
        }
        else
        {
            if (current_direction == d)
            {
                present_time = t;
                finished_time = present_time + 10;
            }
            else
            {
                waiting.pb(t);
                t = finished_time;
                present_time = t;
                finished_time = present_time + 10;
                current_direction = d;
            }
        }
    }
    cout << finished_time;
}
