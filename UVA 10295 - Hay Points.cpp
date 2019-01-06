#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

int main(){
    map <string,int> dictionary;
    string aux;
    string word;
    int money;
    int numpalavras;
    int numjobs;
    int answer;
    cin >> numpalavras >> numjobs;
    for(int i = 1; i <= numpalavras; i++){
        cin >> word >> money;
        dictionary[word] = money;
    }
    for(int i = 1; i <= numjobs; i++){
        answer = 0;
        while(cin >> aux, aux != "."){
            answer += dictionary[aux];
        }
        cout << answer << endl;
    }
    return 0;
}
