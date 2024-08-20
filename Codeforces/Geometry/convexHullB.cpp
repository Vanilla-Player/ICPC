
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define P complex<int>
#define X real()
#define Y imag()


struct pt // Used in this sol   
{
    int x,y;
    pt(int x, int y):x(x),y(y){}
    pt(){}
    pt operator+(pt p){return pt(x+p.x, y+p.y);} 
    pt operator-(pt p){return pt(x-p.x, y-p.y);} 
    int operator*(pt p){return 1LL*(x*p.x+y*p.y);} 
    int operator&(pt p){return 1LL*((x*p.y)-(y*p.x));} 
    int left(pt p, pt q){
        return ((q-p)&(*this-p)) > 0;
    }
};




vector<pt> upper_hull(vector<pt> &v){

    vector<pt> uh;
    // cout << "UPPER HULL METHOD" << endl;
    for (int i = 0; i < v.size(); i++)
    {
       
        while(uh.size() >= 2 && ((uh.back() - uh[uh.size()-2]) & (uh.back() - v[i])) < 0){
            // cout << "DELETED" << endl;
            int val = (uh.back() - uh[uh.size()-2]) & (uh.back() - v[i]);
            // cout << val << endl;
            // cout << uh[uh.size()-1].x << " " << uh[uh.size()-1].y << endl;
            uh.pop_back();
        }
       
        // cout << "ADDED" << endl;
        // cout << v[i].x << " " <<  v[i].y << endl;
        //  if(uh.size() >= 2){
        //     int val = (uh.back() - uh[uh.size()-2]) & (uh.back() - v[i]);
        //     cout << val << endl;
        // }
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
    vector<pt> v(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    sort(v.begin(), v.end(), 
         [] (const pt &a, const pt &b) {
                return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
        });
    vector<pt> v1 = upper_hull(v);
    sort(v.begin(), v.end(), 
         [] (const pt &a, const pt &b) {
                return (a.x == b.x) ? (a.y > b.y) : (a.x > b.x);
        });
    vector<pt> v2 = upper_hull(v);
    // cout << "First Method" << endl;
    // for (int i = 0; i < v1.size(); i++) {
    //     cout << v1[i].x << " " << v1[i].y << endl;
    // }
    // cout << "SECOND METHOD" << endl;
    // for (int i = 0; i < v2.size(); i++) {
    //     cout << v2[i].x << " " << v2[i].y << endl;
    // }

    // cout << "first" << endl;
    // cout << v1[0].x << v1[0].y << endl;

    for (int i = 1; i < v2.size() - 1; i++) {
        v1.push_back(v2[i]);
    }   

    // cout << "SOL" << endl;
    cout << v1.size() << endl;
    for (auto i: v1)
        cout << i.x << " " << i.y << endl;

return 0;

}