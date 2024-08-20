#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main(){

    ll n;

    cin >> n;

    vector<ll >nums(5,0);

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        ll mod = num%5;
        if(mod == 0){
            ans++;
        }else{
            nums[mod]++;
        }
    }

    if(nums[4] > 0 && nums[1] > 0){ // GASTA 2 : 1,4
        // cout << "1" << endl;
        if(nums[1] > nums[4]){

            ans+=nums[4];
            nums[1]-=nums[4];
            nums[4]=0;
        }else{
            ans+=nums[1];
            nums[4]-= nums[1];
            nums[1] = 0;
        }
    }

    if(nums[3] > 0 && nums[2] > 0){ // Gasta 2 : 3,2

        // cout << "2" << endl; 
        if(nums[3] > nums[2]){
            ans+= nums[2];
            nums[3]-=nums[2];
            nums[2]=0;
        }else{
            ans+=nums[3];
            nums[2]-=nums[3];
            nums[3] = 0;
        }
    }

    if(nums[3] > 0 && nums[1]/2 > 0){ // Gasta 3:  1 , 1 , 3
// cout << "3" << endl; 
        if(nums[1]/2 > nums[3]){
            ans+=nums[3];
            nums[1]-=nums[3]*2;
            nums[3]=0;
        }else{
            ans+=nums[1]/2;
            nums[3]-= nums[1]/2;
            nums[1] = 0;
        }
    }

    // falta 1, 2 , 2

    if(nums[4] > 0 && nums[3]/2 > 0){  
    // Gasta 3  3, 3 4
            if(nums[3]/2 > nums[4]){
                ans+=nums[4];
                nums[3] -= nums[4]*2;
                nums[4]= 0;
            }else{
                ans+=nums[3]/2;
                nums[4] -= nums[3]/2;
                nums[3]= 0;
            }
        
        
    }

 
     

    if(nums[4]/2 > 0 && nums[2] > 0){

         // Gasta 3 2,4,4
            if(nums[4]/2 > nums[2]){
                ans+=nums[2];
                nums[4] -= nums[2]*2;
                nums[2]= 0;
            }else{
                ans+=nums[4]/2;
                nums[2] -= nums[4]/2;
                nums[4]= 0;
            }
        

    }

    if(nums[2] > 0 && nums[1]/3 > 0){ // Gasta 4 1,1,1,2
// cout << "4" << endl; 
        if(nums[1]/3 > nums[2]){
            ans+=nums[2];
            nums[1]-=nums[2]*3;
            nums[2]=0;
        }else{
            ans+=nums[1]/3;
            nums[2]-= nums[1]/3;
            nums[1] = 0;
        }
    }
     // falta 1,3,3,3

        if(nums[4]/3 > 0 && nums[3] > 0){ // GASTA 4 3,4,4,4
            if(nums[4]/3 > nums[3]){
                ans+=nums[3];
                nums[4] -= nums[3]*3;
                nums[3] = 0;
            }else{
                ans+=nums[4]/3;
                nums[3]-=nums[4]/3;
                nums[4] = 0;
            }
        }

            if(nums[2]/3 > 0 && nums[4] > 0){ // Gasta 4 2,2,2,4
            if(nums[2]/3 > nums[4]){
                ans+=nums[4];
                nums[2] -= nums[4]*3;
                nums[4] = 0;
            }else{
                ans+=nums[2]/3;
                nums[4]-=nums[2]/3;
                nums[2] = 0;
            }
        }

    for (int i = 1; i < 5; i++)
    { // Gastan 5
        ans+= (nums[i]/5);
        nums[i]-=nums[i]*5;
    }
    

    cout << ans << endl;

}