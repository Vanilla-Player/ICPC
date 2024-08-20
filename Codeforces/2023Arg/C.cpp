#include <bits/stdc++.h>
#include <cstdio>
 
 // SOLUTION WRONG ANSWER TEST 9
using namespace std;
long long qFriends;

 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> qFriends;
    vector<int> A;
    vector<int> B;
 
    for (int i = 0; i < qFriends; i++){
        int l;
        cin >> l;
        A.push_back(l);
    }
 

    for (int i = 0; i < qFriends; i++){
        int l;
        cin >> l;
        B.push_back(l);
    }
 
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    for (int i = 0; i < qFriends; i++)
    {
        cout << B[i] << endl; 
    }
    
    vector<int> c;
    for (int i = 0; i < qFriends; i++)
    {
        c.push_back(A[i] + B[i]);
    }
    
    int ans = *max_element(c.begin() - c.end()) - *min_element(c.begin(), c.end());

    cout << ans << endl;
    
    return 0;
}
