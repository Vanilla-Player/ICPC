#include <bits/stdc++.h>


using namespace std;

// Function to calculate the kth child to be removed
long long calculateRemovedChild(long long totalChildren,
                                long long kthChild)
{
    // Base case: if there's only one child left, it's the
    // one to be removed
    if (totalChildren == 1)
        return 1;
    // If k is less than or equal to half the total number
    // of children
    if (kthChild <= (totalChildren + 1) / 2)
    {
        if (2 * kthChild > totalChildren)
            return (2 * kthChild) % totalChildren; //Resto, aceptable
        else
            return 2 * kthChild; // Deducible
    }

    
    // Calculate the kth child to be removed for half the
    // total number of children
    long long temp = calculateRemovedChild(
        totalChildren / 2,
        kthChild - (totalChildren + 1) / 2);
    // If the total number of children is odd, return 2*temp
    // + 1
    if (totalChildren % 2 == 1)
        return 2 * temp + 1;
    // Otherwise, return 2*temp - 1
    return 2 * temp - 1;
}

int main()
{
      long long totalChildren, kthChild;
      int t;
    cin >> t;
    while(t--){
    cin >> totalChildren >> kthChild;
    cout << calculateRemovedChild(totalChildren, kthChild)
             << "\n";
    }
}