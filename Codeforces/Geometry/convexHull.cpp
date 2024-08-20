
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define P complex<int>
#define X real()
#define Y imag()

int cross(P &a, P &b, P &c) {
    P u = c - b;
    P v = a - b;
    int cp = (conj(u) * v).Y;
    return (cp > 0) - (cp < 0);
}

vector<P> hull(vector<P> &v ){
    vector <P> ans = {{v[0]}};
    for(int i = 1; i < v.size(); i++){
        while(ans.size() > 1){
            P b = ans.back();
            ans.pop_back();
            P a = ans.back();
            P c = v[i];

            if(cross(a,b,c) != 1){
                ans.push_back(b);
                break;
            }
        }
        ans.push_back(v[i]);
    }
    return ans;
}


vector<P> upper_hull(vector<P> &v){

    vector<P> uh;
    cout << "UPPER HULL METHOD" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        while(uh.size() >= 2 && (conj(uh[uh.size()-1]-uh[uh.size()-2])*v[i]-uh[uh.size()-2]).Y > 0){
            uh.pop_back();
        }
        cout << "ADDED" << endl;
        cout << v[i].X << " " <<  v[i].Y << endl;
        uh.push_back(v[i]);
    }
    
    return uh;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin >> n;
    vector<P> v(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    sort(v.begin(), v.end(), 
         [] (const P &a, const P &b) {
                return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
        });
    vector<P> v1 = hull(v);
    vector<P> v2 = upper_hull(v);
    cout << "First Method" << endl;
    for (int i = 1; i < v1.size(); i++) {
        cout << v1[i].X << " " << v1[i].Y << endl;
    }
    cout << "SECOND METHOD" << endl;
    for (int i = 1; i < v2.size(); i++) {
        cout << v2[i].X << " " << v2[i].Y << endl;
    }

return 0;

    sort(v.begin(), v.end(),
         [] (const P &a, const P &b) {
                return (a.X == b.X) ? (a.Y > b.Y) : (a.X > b.X);
        });
    // vector<P> v2 = hull(v);
    for (int i = 1; i < v2.size(); i++) {
        if (v2[i] == v1[0]) break;
        v1.push_back(v2[i]);
    }
    cout << v1.size() << endl;
    for (auto i: v1)
        cout << i.X << " " << i.Y << endl;
}