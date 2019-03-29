#include <bits/stdc++.h>

using namespace std;

vector<int> adjlist[110];
int visitados[110];
vector<char> answer;
vector<string> registro;
map<int,char> dic2;

void toposort(int x){
    int u;
    visitados[x] = 1;
    for(int i = 0; i < (int)adjlist[x].size(); i++){
        u = adjlist[x][i];
        if(visitados[u] == 0){
            toposort(u);
        }
    }
    answer.push_back(dic2[x]);
}

pair<char,char> find(string auxiliar1, string auxiliar2){
    pair<char, char> dale;
    /*if(auxiliar2.length() > auxiliar1.length()){
        dale.first = auxiliar1[auxiliar1.length() - 1];
        dale.second = auxiliar2[auxiliar2.length() - 1];
        return dale;
    }*/
    int limite = min(auxiliar1.length(), auxiliar2.length());
    for(int i = 0; i < limite; i++){
        if(auxiliar1[i] != auxiliar2[i]){
            dale.first = auxiliar1[i];
            dale.second = auxiliar2[i];
            return dale;
        }
    }
    dale.first = auxiliar1[auxiliar1.length() - 1];
    dale.second = auxiliar2[auxiliar2.length() - 1];
    return dale;
}

int main(){
    string aux;
    int chave = 1;
    map<char,int> dictionary;
    pair<char,char> ordem;
    while(true){
        cin >> aux;
        if(aux == "#"){
            break;
        }
        registro.push_back(aux);
    }
    for(int i = 0; i <= (int)registro.size() - 2; i++){
        ordem = find(registro[i], registro[i + 1]);
        //cout << ordem.first << " " << ordem.second << endl;
        if(dictionary.find(ordem.first) == dictionary.end()){
            dictionary[ordem.first] = chave;
            dic2[chave] = ordem.first;
            chave++;
        }
        if(dictionary.find(ordem.second) == dictionary.end()){
            dictionary[ordem.second] = chave;
            dic2[chave] = ordem.second;
            chave++;
        }
        adjlist[dictionary[ordem.first]].push_back(dictionary[ordem.second]);
    }
    /*for(map<char,int>::iterator it = dictionary.begin(); it != dictionary.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }*/
    for(int i = 1; i <= chave - 1; i++){
        if(visitados[i] == 0){
            toposort(i);
        }
    }
    for(int a = (int)answer.size() - 1; a >= 0; a--){
        printf("%c", answer[a]);
    }
    return 0;
}
