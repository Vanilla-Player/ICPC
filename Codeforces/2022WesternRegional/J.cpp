    #include <bits/stdc++.h>
    using namespace std;
    
    
    #define int long long
    
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


    int gcd(int n1,int n2){
        if(n2==0)return n1;
        return gcd(min(n1,n2),max(n1,n2)%min(n1,n2));
    }


    void solve( int n, set<int> &ans){

        for(int i = 1; i*i <= n; i++){
            if(n % i == 0){
                ans.insert(i);
                ans.insert(n / i);
            }
        }
    }

    // g++ -std=c++11 -O2 -Wall test.cpp -o test
    signed main()
    {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int t;
        cin >> t;
        fori(j, t)
        {
            set<int> a_values;
            int w, h;
            cin >> w >> h;

            solve(gcd(w, h - 2), a_values);
            solve(gcd(w - 2, h), a_values);
            solve(gcd(w - 1, h - 1), a_values);
            solve(gcd(w - 1, gcd(h - 2, h)), a_values); // caso borde
            solve(gcd(h - 1, gcd(w, w - 2)), a_values); // caso borde

            cout << a_values.size();
            for(auto a : a_values){
                cout << " " << a;
            }
            cout << '\n';
        }
    }