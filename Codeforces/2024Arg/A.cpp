#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


#define fori(i,n) for(int i=0;i < (n);i++)
#define fora(i,a,n) for(int i=(a);i <= (n);i++)
#define ford(i,a,n) for(int i=(n);i >=(n);i--)

vector<string > matriz = {"libre", ".", ".", ".", ".", ".", ".", ".", ".", "."};
vector<int> played(10);

vector<vector<int> >cell_rest(10);
vector<int> res_of(10);
vector<int> no_pb(10);

ll n, q_no_pb;
bool has_winner = false;
string the_winner = "";



bool isFree(int cell){ // para ver si esta libre en algun momento
    for(auto res: cell_rest[cell]){
        if((!played[res]))return false;
    }
    return true;
}

bool winner(){
    if(matriz[1] == matriz[2] && matriz[2] == matriz[3] && matriz[1] != "."){
        // cout << "1" << endl;
        return true;
    }
    if(matriz[4] == matriz[5] && matriz[5] == matriz[6] && matriz[6] != "."){
        // cout << "2" << endl;
        return true;
    }
    if(matriz[7] == matriz[8] && matriz[8] == matriz[9] && matriz[9] != "."){
        // cout << "3" << endl;
        return true;
    }
    if(matriz[1] == matriz[5] && matriz[5] == matriz[9] && matriz[9] != "."){
        // cout << "4" << endl;
        return true;
    }
    if(matriz[3] == matriz[5] && matriz[5] == matriz[7] && matriz[7] != "."){
        // cout << "5" << endl;
        // cout << matriz[3] << " " << matriz[5] << " " << matriz[7] << endl; 
        return true;
    }
    return false;
}

void showTable(){
    cout << endl;
        fora(i,1,3){
            cout << matriz[i] << " ";  
        }
         cout << endl;
        fora(i,4,6){
            cout << matriz[i] << " ";  
        }
         cout << endl;
        fora(i,7,9){
            cout << matriz[i] << " ";  
        }
        cout << endl;
        return;
}

// porque [0] tiene valor???
void play(string player,int from, int can_win, int played_res){

    bool false_winner = false;
    if(winner()){
       // Si gana, pero no fue despues de una restriccion liberada, entonces no cuento la branch
       if(can_win){
        // showTable();
        has_winner = true;
        the_winner = "X" == player?"O":"X";

       }else{
        return;
       }

    }
    // if(can_win && winner()){ // 
     
    //     // the_winner = player;
    // }

    fora(i,1,9){
        if(has_winner)continue;
        if(played[i])continue;
        if(!isFree(i))continue;
        bool played_np = false;
        if(q_no_pb && !no_pb[i])continue;
        if (no_pb[i])
        {
            played_np = true;
            q_no_pb--;
        }
        
        // Primero jugar los que no son restriccion
        // Despues, jugar los que si los on
        if(played_res){
            can_win = 1;
        }else{
            can_win = 0;
        }
        bool this_played_res = false;
        int aux = 0;
        if(res_of[i]){
            // cout << "PLAYING REST" << endl;
            // cout<< "rest_of: " << res_of[i] << "\n";
            this_played_res = true;
            if(res_of[i] == 1){
                played_res = 1;
            }
            aux = res_of[i];
            res_of[i] = 0;
        }else{
            played_res = 0;

        }
        // cout << "FROM" << endl;
        // cout << from << endl;
        // cout << "PLAY" << endl;
        // cout << i << endl;
        played[i] = 1;
        if(player == "X"){
            matriz[i] = "X";
            play("O",i ,can_win,played_res);
        }else{
            matriz[i] = "O";
            play("X",i ,can_win,played_res);
        }
        matriz[i] = ".";
        if(this_played_res){
            res_of[i] = aux;
        }
        if(played_np){
            q_no_pb++;
        }
        played[i] = 0;
    }
}


int main(){

    cin >> n;
    fori(i, n){
        int cell, res;
        cin >> res >> cell;
        cell_rest[cell].push_back(res);
        res_of[res]++;
    }

    fora(i,1,9){

        if(cell_rest[i].size() == 0 && !res_of[i]){
            no_pb[i] = 1;
            q_no_pb++;
        }

    }

    // cout << "q_to_play: " << q_to_play << endl;
    // return 0;

    int can_win = n == 0?1:0;
    play("X",0,can_win,0);


    if(has_winner){
        cout << the_winner << endl;
    }else{
        cout << "E" << endl;
    }

}