#include <bits/stdc++.h>

using namespace std;

int main(){
    int flag; // A flag vai me indicar se eu encontrei um ponto de ff/drugstore
    int flag1; //Vai me indicar se eu estou em um ponto de partida ou em um ponto de chegada
    int length;
    char mark1;
    int dist;
    int partida, chegada;
    int minimum = 99999999;
    vector <char> highway;
    char aux;
    scanf("%d", &length);
    while(length != 0){
        minimum = 99999999;
        flag = 0;
        flag1 = 0;
        for(int i = 0; i < length; i++){
            scanf(" %c", &aux);
            highway.push_back(aux);
        }
        for(int i = 0; i < highway.size(); i++){
            
            if(highway[i] == 'Z'){
                flag = 1;
                break;
            }
            if(highway[i] == 'R' || highway[i] == 'D'){
                if(flag1 == 0){
                    mark1 = highway[i];
                    partida = i;
                    flag1 = 1;
                }
                else if(flag1 == 1){
                    if(highway[i] == mark1){
                        partida = i;
                    }
                    if(highway[i] != mark1){
                        dist = i - partida;
                        //printf("partida: %d -- chegada: %d --- dist: %d\n", partida, i, dist);
                        if(minimum > dist){
                            minimum = dist;
                        }
                        mark1 = highway[i];
                        partida = i;
                    }
                }
            }
        }
        if(flag == 1){
            printf("0\n");
        }
        else{
            printf("%d\n", minimum);
        }
        highway.clear();
        scanf("%d", &length);
    }
    return 0;
}
