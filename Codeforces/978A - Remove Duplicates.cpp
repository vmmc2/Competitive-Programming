#include <bits/stdc++.h>
#include <cmath>
 
using namespace std;
 
int main(){
    int num, aux;
    vector<int>array;
    set<int> jafoi;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        scanf("%d", &aux);
        array.push_back(aux);
    }
    int final = num - 1;
    for(int i =  final; i >= 0; i--){
        if(jafoi.find(array[i]) == jafoi.end()){ //o numero nao foi visto ainda
            jafoi.insert(array[i]); //insere o numero
        }else if(jafoi.find(array[i]) != jafoi.end()){ //ja vi esse numero antes
            array[i] = -69;
        }
    }
    printf("%d\n", (int)jafoi.size());
    for(int i = 0; i < (int)array.size(); i++){
        if(array[i] != -69){
            printf("%d ", array[i]);
        }
    }
    
    return 0;
}
