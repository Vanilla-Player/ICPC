#include <bits/stdc++.h>

using namespace std;

#define ll long long

long long n,m,k;

vector<int> apariciones(26,0);


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        int asci_value = s[i] - 'A';
        if(asci_value < k){
            apariciones[asci_value]++;
        }
        
    }

    int minimo = 1e5+2;

    for (int i = 0; i < k; i++)
    {
        minimo = min(minimo, apariciones[i]);
    }
    
    if(minimo == 0){
        cout << '0' << endl;
    }else{
        cout << minimo*k << endl;
    }
    

}