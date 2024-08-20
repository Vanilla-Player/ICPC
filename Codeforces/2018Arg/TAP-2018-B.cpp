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
        ll D, M, D1, N, D2;
        cin >> D >> M >> D1 >> N >> D2;

        if (D1 <= D)
        {
            cout << -1;
            return 0;
        }

        ll l1 = 1;


        ll dis_total = D * 2;
        int cant_mejores = 0;
        while (cant_mejores < M && dis_total > 0)
        {
            cant_mejores++;
            dis_total -= D1;
            dis_total *= 2;
        }
        if (cant_mejores <= M && dis_total <= 0)
        {
            cout << cant_mejores;
            return 0;
        }

        ll NEW_D = dis_total / 2;
        if (D2 <= NEW_D)
        {
            cout << -1;
            return 0;
        }
        if (D2 >= NEW_D * 2)
        {
            cout << cant_mejores + 1;
            return 0;
        }


        ll l = 1;
        ll r = 1e10;

        if(1LL*(D2 - NEW_D)*pow(2,l) >= NEW_D*2){
            cout << l + cant_mejores << endl;
            return 0;
        }

        while (l + 1 < r)
        {
            ll mid = (l + r)/2;

            if(1LL*(D2 - NEW_D)*pow(2,mid) >= NEW_D*2){
                r= mid;
            }else{
                l = mid;
            }
        }
        

        // float new_d = NEW_D;
        // float d2 = D2;
        // ll cant_amigos = long(31-__builtin_clz(new_d/(d2 - new_d)));

            // cout << l << endl;
            // cout << r << endl;
        // o r
        if (1LL*(D2 - NEW_D)*pow(2,l) >= NEW_D*2 && l <= N)
        {
            cout << r + cant_mejores << endl;
            return 0;
        }else if(1LL*(D2 - NEW_D)*pow(2,r) >= NEW_D*2 && r <= N){
            cout << l + cant_mejores << endl;
            return 0;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
