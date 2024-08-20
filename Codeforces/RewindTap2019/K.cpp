#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<pair<int, int> > Dschool;
    vector<pair<int, int> > Jschool;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char school;
        int l,r;
        cin >> school >> l >> r;
        if(school == 'D'){
            Dschool.push_back(make_pair(l,r));
        }else{
            Jschool.push_back(make_pair(l,r));
        }
    }
    
    int maxRange = 0;
    for (int sD = 0; sD < Dschool.size(); sD++)
    {
        pair<int, int> studentD = Dschool[sD];
        int lD = studentD.first;
        int rD  = studentD.second;
        for (int sJ = 0; sJ < Jschool.size(); sJ++)
        {
            pair<int, int> studentJ = Jschool[sJ];
            int lJ = studentJ.first;
            int rJ  = studentJ.second;
            if(lD < rJ && lJ < rD){
                int leftest;
                int rightest;
                if(lJ < lD){
                    leftest = lD;
                }else leftest = lJ;
                if(rJ < rD){
                    rightest = rJ;
                }else rightest = rD;
                int range = abs(leftest - (rightest));
                maxRange = max(range, maxRange);
            }

        }
        
    }
    
    cout << maxRange << endl;
    
    return 0;
}