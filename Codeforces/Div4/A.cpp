#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){

    int N;
    string word1;
    string word2;
    vector<string> words1;
    vector<string> words2;


    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> word1 >> word2;
        char aux = word1[0];
        word1[0] = word2[0];
        word2[0] = aux;
        words1.push_back(word1);
        words2.push_back(word2);
    }


    for (int i = 0; i < N; i++)
    {
        cout << words1[i] << " " << words2[i] << endl;
    }
    

    return 0;
}