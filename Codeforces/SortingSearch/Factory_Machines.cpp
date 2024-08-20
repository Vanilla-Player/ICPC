
#include <bits/stdc++.h>
#define lli long long 




using namespace std;

lli machinesNumber, totalProducts, maxVal = 0;
vector<lli> machines;



bool canMakeProductsAtTime(lli time){
    lli products = 0;
    for (lli i = 0; i < machinesNumber; i++)
    {
        lli timeForProduct = machines[i];
        products += (time / timeForProduct);
    }
   

    return products >= totalProducts;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> machinesNumber >> totalProducts;

    for (lli i = 0; i < machinesNumber; i++)
    {
        lli timeForProduct;
        cin >> timeForProduct;
        machines.push_back(timeForProduct);
        maxVal = max(maxVal, timeForProduct);
    }
    lli lowLT = 0;
    lli maxLT = totalProducts * maxVal + 1; 
    while (lowLT <= maxLT)
    {
        lli time = (lowLT + maxLT)/2;
        if(canMakeProductsAtTime(time)){
            maxLT = time - 1;
        }else{
            lowLT = time + 1;
        }
    }
    
    cout << lowLT << endl;

    return 0;

}

