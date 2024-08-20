
#include <bits/stdc++.h>
#include <algorithm>



using namespace std;


int f(int m, int b,vector<int> rats, int hole_pos, int cat_pos, int &saves){
    int time = 0, cont = 0;

    for (int i = m; i < b; i++)
    {
        time += hole_pos - rats[i];
        cont++;
    }
    // cout << "time pass " << time << "\n";
    if(time - cat_pos > cat_pos && time > 0){
        saves += cont;
        return time;
    }


    return 0;
}

int main(){

    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int cases;
    cin >> cases;
    for(int index = 0; index < cases ; index++){
        int hole_pos, k;
        int cat_pos = 0;
        vector<int> rats;
        cin >> hole_pos >> k;
        for (int i = 0; i < k; i++)
        {
            int number = 0;
            cin >> number;
            rats.push_back(number);
        }
    
        sort(rats.begin(),rats.end());
        int a = 0, b = k;
        int saves = 0;
        while (a <= b)
        {

            int m = (a+b) / 2;
            int result = f(m, b, rats, hole_pos, cat_pos, saves);
            if(result){
                // cout << "true" << "\n";
                b = m - 1;
                cat_pos += result;
                // cout << "cat position " << cat_pos << "\n";
            } else{
                // cout << "false" << "\n";

                a = m+1;
            }
            
        }
        cout << saves << "\n";
    }

}

