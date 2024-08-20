#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,A,B;
 
    cin >> n >> A >> B;
 
    vector<int> cupcakes; 
 
    for (int i = 0; i < n; i++)
    {
        int spiciness;
        cin >> spiciness;
        cupcakes.push_back(spiciness);
    }
 
    
 
    if(A < 0){
       sort(cupcakes.rbegin(),cupcakes.rend());
    }else{
        sort(cupcakes.begin(),cupcakes.end());
    }

    int acum_spiciness = 0;
    int eaten = 0;
    for (int j = 0; j < n; j++)
    {
        acum_spiciness += (eaten+1)*(A*cupcakes[j]+B);
        eaten++;
    }
 
    cout << acum_spiciness;
 
}