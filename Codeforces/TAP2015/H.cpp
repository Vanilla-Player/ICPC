#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, sub, countSub;
    int times = 0;
    while(cin >> N){
        string NString = to_string(N);
        string MString;
        M = 0;

        while (N - M > 0)
        {
            N = N - M;
            NString = to_string(N);
            MString = NString; 
            sort(MString.begin(),MString.end());
            M = stoi(MString);
            times++;   
        }
        


        cout << times << endl;
        times = 0;
    }


   

    return 0;

}

