#include <bits/stdc++.h>
#include <string>

using namespace std;

bool answer = false;
int numOfErased = 20;


void backtrack(string &s, int cursor, int n, vector<bool> &visited){
    if(cursor == n){ //morgou.. hora de checar a string...
        string aux = "";
        for(int i = 0; i < (int)s.size(); i++){
            if(visited[i] == true) aux += s[i];
        }
        if(aux == "") return;
        if(stol(aux) % 3 == 0){
            answer = true;
            numOfErased = min(numOfErased, n - (int)aux.size());
        }
        return;
    }
    visited[cursor] = true;
    backtrack(s, cursor + 1, n, visited);
    visited[cursor] = false;
    backtrack(s, cursor + 1, n, visited);

    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    if(stol(s) % 3 == 0){
        cout << "0" << endl;
        return 0;
    }

    int n = (int)s.size();
    int cursor = 0;
    vector<bool> visited(n, false);

    backtrack(s, cursor, n, visited);

    if(answer) cout << numOfErased << endl;
    else cout << "-1" << endl;


    return 0;
}
