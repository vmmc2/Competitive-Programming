#include <bits/stdc++.h>

using namespace std;

int main(){
    //tem que fazer a análise da string de trás para frente
    string s;
    char aux;
    int tam;
    int flag = 0;
    int caso  = 1;
    vector <stack<char>> containers;
    while(true){
        cin >> s;
        if(s == "end"){
            break; //cheguei ao fim dos casos de teste
        }
        tam = (int)s.length() - 1;
        containers.push_back(stack<char>());
        containers[0].push(s[tam]);
        for(int i = tam - 1; i >= 0; i--){
            flag = 0;
            aux = s[i];
            for(int j = 0; j < (int)containers.size(); j++){
                if((int)aux >= (int)containers[j].top()){
                    containers[j].push(aux);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                containers.push_back(stack<char>());
                int dale = (int)containers.size() - 1;
                containers[dale].push(aux);
            }
        }
        printf("Case %d: %d\n", caso, (int)containers.size());
        caso++;
        containers.clear();
    }
    return 0;
}
