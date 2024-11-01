#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++20 -02 -wall template.cpp -o template
 
#define forr(i,a,b) for(int i=(int)a ; i<(int)b ; i++)
#define forn(i, n) for(int i = 0; i < n; i ++)
#define all(x) (x).begin(),(x).end()
#define fst first
#define snd second
#define pb(x) push_back(x)
typedef long long ll;
typedef pair<int,int> ii;
const int MAXN = -1;
const double EPS = 1e-9;

ll gcd(ll n1,ll n2){
    if(n2==0)return n1;
    return gcd(min(n1,n2),max(n1,n2)%min(n1,n2));
}

vector<int> rest[10];
bool turn=true;//true x, false o

int win(vector<int> b){
    if(b[1]!=-1 && b[1]==b[2] && b[1]==b[3])return b[1];
    if(b[4]!=-1 && b[4]==b[5] && b[4]==b[6])return b[4];
    if(b[7]!=-1 && b[7]==b[8] && b[7]==b[9])return b[7];
    if(b[1]!=-1 && b[1]==b[4] && b[1]==b[7])return b[1];
    if(b[2]!=-1 && b[2]==b[5] && b[2]==b[8])return b[2];
    if(b[3]!=-1 && b[3]==b[6] && b[3]==b[9])return b[3];
    if(b[1]!=-1 && b[1]==b[5] && b[1]==b[9])return b[1];
    if(b[3]!=-1 && b[3]==b[5] && b[3]==b[7])return b[3];
    return -1;
}

int game(vector<int> &b,bool t,int nt){
    if(win(b)!=-1)return win(b);
    int sol=!t,cant=0;
    forr(i,1,10){
        cant++;
        if(b[i]==-1){
            bool can=true;
            for(auto u:rest[i])if(b[u]==-1){
                can=false;
                break;
            }
            if(can){
                cant=0;
                b[i]=t;
                int res=game(b,!t,nt+1);
                b[i]=-1;
                if(res==t)return t;
                else if(res==-1)sol=-1;
            }
        }
    }
    if(cant==9)return -1;
    else return sol;
}

int main(){
    cout.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin >> n;
    vector<int> board(10,-1);
    // board[5]=1;
    forn(i,n){
        cin >>a >> b;
        rest[b].pb(a);
    }
    int w=game(board,true,1);
    if(w==-1)cout << 'E' <<'\n';
    if(w==1)cout << 'X' <<'\n';
    if(w==0)cout << 'O' <<'\n';
    
    return 0;
}