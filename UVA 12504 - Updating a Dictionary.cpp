#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){
    int numcasos;
    map <string,string> oldic;
    map <string,string> newdic;
    set <string> retiradas;
    set <string> ganhas;
    set <string> mudadas;
    vector<string> retiradas1;
    vector<string> ganhas1;
    vector<string> mudadas1;
    string aux1, aux2;
    string key, value;
    int tam1, tam2;
    int flag = 0;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        oldic.clear();
        newdic.clear();
        retiradas.clear();
        retiradas1.clear();
        mudadas1.clear();
        mudadas.clear();
        ganhas1.clear();
        ganhas.clear();
        cin >> aux1;
        tam1 = aux1.length();
        key = "";
        value = "";
        //cout << aux1 << endl;
        //pegando a entrada para o primeiro dicionario
        for(int j = 1; j <= tam1-1;){
            //cout << "entrei\n";
            while(aux1[j] != ':'){
                key += aux1[j];
                j++;
                if(j == tam1-1){
                    goto end;
                }
            }
            while(aux1[j] != ','){
                value += aux1[j];
                j++;
                if(j == tam1-1){
                    oldic[key] = value;
                    goto end;
                }
            }
            j++;
            oldic[key] = value;
            key = "";
            value = "";
        }
        end:
        //pegando a entrada para o segundo dicionario
        cin >> aux2;
        if(aux1 == aux2){
            printf("No changes\n");
            printf("\n");
            continue;
        }    
        tam2 = aux2.length();
        key = "";
        value = "";
        for(int j = 1; j <= tam2-1;){
            //cout << "entrei\n";
            while(aux2[j] != ':'){
                key += aux2[j];
                j++;
                if(j == tam2-1){
                    goto end1;
                }
            }
            while(aux2[j] != ','){
                value += aux2[j];
                j++;
                if(j == tam2-1){
                    newdic[key] = value;
                    goto end1;
                }
            }
            j++;
            newdic[key] = value;
            key = "";
            value = "";
        }
        end1:
        //fim do processo de pegar a entrada do dicionario
        if(aux1 == "{}"){
            oldic.clear();
        }
        if(aux2 == "{}"){
            newdic.clear();
        }
        int flagperdeu = 0;
        int flagmudou = 0;
        int flagganhou = 0;
        int didnotchange = 0;
        for(map<string,string>:: iterator it = oldic.begin(); it != oldic.end(); ++it){
               if(newdic.find(it->first) == newdic.end()){
                   retiradas.insert(it->first);
                   flagperdeu = 1;
                   didnotchange = 1;
               }
               if(newdic.find(it->first) != newdic.end()){
                   if(oldic[it->first] != newdic[it->first]){
                       mudadas.insert(it->first);
                       flagmudou = 1;
                       didnotchange = 1;
                   }
               }
        }
        for(map<string,string>:: iterator it = newdic.begin(); it != newdic.end(); ++it){
            if(oldic.find(it->first) == oldic.end()){
                flagganhou = 1;
                didnotchange = 1;
                ganhas.insert(it->first);
            }
        }
        
        if(didnotchange == 0){
            printf("No changes\n");
            printf("\n");
            continue;
        }
        else{
            if(flagganhou == 1){
                printf("+");
                for(set<string>:: iterator dale = ganhas.begin(); dale != ganhas.end(); ++dale){
                    ganhas1.push_back(*dale);
                }
                for(int k = 0; k < ganhas1.size(); k++){
                    if(k == ganhas1.size()-1){
                        cout << ganhas1[k] << endl;
                    }
                    else{
                        cout << ganhas1[k] << ",";
                    }
                }
            }
            if(flagperdeu == 1){
                printf("-");
                for(set<string>:: iterator dale = retiradas.begin(); dale != retiradas.end(); ++dale){
                    retiradas1.push_back(*dale);
                }
                for(int k = 0; k < retiradas1.size(); k++){
                    if(k == retiradas1.size()-1){
                        cout << retiradas1[k] << endl;
                    }
                    else{
                        cout << retiradas1[k] << ",";
                    }
                }
            }
            if(flagmudou == 1){
                printf("*");
                for(set<string>:: iterator dale = mudadas.begin(); dale != mudadas.end(); ++dale){
                    mudadas1.push_back(*dale);
                }
                for(int k = 0; k < mudadas1.size(); k++){
                    if(k == mudadas1.size()-1){
                        cout << mudadas1[k] << endl;
                    }
                    else{
                        cout << mudadas1[k] << ",";
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
