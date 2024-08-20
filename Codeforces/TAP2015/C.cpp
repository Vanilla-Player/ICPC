
#include <bits/stdc++.h>
#include <algorithm>



using namespace std;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    //21 3 3 2
    //N  S J D 
    // AABA BBB ABBB ABABABBABB
    // 8 13
    // 1 3
    // A B

    int N,S,J,D;

    string match;
    while(cin >> N >> S >> J >> D){
    cin >> match;
    bool winner = false;
    int countA = 0;
    int countB = 0;
    int setA = 0;
    int setB = 0;
    for(int i = 0; i < N; i++){
        char game = match[i];
        if(game == 'A'){
            countA++;
        }else{
            countB++;
        }

        if(countA >= J){
            if(countA - D >= countB){
                setA++;
                countA = 0;
                countB = 0;
            }
        }


        if(countB >= J){
            if(countB - D >= countA){
                setB++;
                countA = 0;
                countB = 0;
            }
        }

        if(setB >= S){
            winner = true;
            cout << setA << " " << setB << endl;
            break;
        }

        if(setA >= S){
            winner = true;
            cout << setA << " " << setB << endl;
            break;
        }

    }

        if(!winner){
            cout << 0 << " " << 0 << endl;
        }

    }

    return 0;

}

