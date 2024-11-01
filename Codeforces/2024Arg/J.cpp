#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fori(i,n) for(int i = 0;i < (n); i++)
#define fora(i,a,n) for(int i = (a);i <= (n); i++)

#define pb push_back

#define dprint(v) cout << #v"=" << v << endl //;)
// const int MAX_N = 300005;

vector<ll> nums;
ll n,s,e,x;

int main(){

    cin >> n >> x;

    fori(i,n){
        ll num;
        cin >> num;
        nums.pb(num);
    }

    sort(nums.begin(), nums.end());

    vector<ll>sums(n-1);

    ll countX = 0;
    ll firstX = 0;
    ll lastX = 0;
    bool first = false;
    ll adjs = 0;
    fora(i,1,n - 1){
        ll suma = nums[i] + nums[i - 1];
        sums[i - 1] = suma;
        // dprint(suma);
        if(suma == x){
            if(!first){
                first = true;
                firstX = i - 1;
            }
            countX++;
        }else if(first){
            first = false;
            lastX = i - 1;
        }
        adjs++;
    }
    // dprint(countX);
    if(countX >= adjs - countX){
        cout << "*" << endl;
        return 0;
    }

    ll leftChanges =  (firstX)/2; // por ahora creo que esto es  firstX + 1
    ll rightChanges = (n-lastX)/2; // por ahora

    bool justLeft = false;

    bool justRight = false;

    if(leftChanges >= (countX)/2){
        justLeft = true;
    } 

    if(!justLeft && rightChanges >= (countX)/2){
        justRight = true;
    } 

    ll index = 0;
    if(!justRight){
        while(leftChanges--){
            ll aux = nums[index];
            nums[index] =  nums[firstX];
            nums[firstX] = aux;
            firstX+= 2;
            index+= 2;
        }
    }    

    if(!justLeft){
        index = n-1;
        while(rightChanges--){
            ll aux = nums[index];
            nums[index] =  nums[firstX];
            nums[firstX] = aux;
             firstX+= 2;
            index-= 2;
        }
    }

    fori(i,n){
        cout << nums[i] << " " ;
    }
    cout << endl;

}