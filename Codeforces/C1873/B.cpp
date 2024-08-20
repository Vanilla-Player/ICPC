
#include <bits/stdc++.h>



using namespace std;

int product_of_vector(vector<int> numbers){

    int accumulate = 1;
    for(int i = 0; i < numbers.size() ; i++ ){
        
        accumulate *= numbers[i];
    }

    return accumulate;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases;
    cin >> cases;
    for(int index = 0; index < cases ; index++){
        int length, max_product = 0;
        vector<int> numbers;
        cin >> length;
        for (int j = 0; j < length; j++){
            int number = 0;
            cin >> number;
            numbers.push_back(number);
        }
        
        for (int j = 0; j < length; j++)
        {
            vector<int> modified_numbers = numbers;
            modified_numbers[j]+= 1;
            
            int possible_max = product_of_vector(modified_numbers);

            if(max_product < possible_max){
                max_product = possible_max;
            }          
            
        }

        cout << "\n";
        cout << max_product; 
        
    }

}

