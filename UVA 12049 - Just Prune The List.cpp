#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctype.h>

using namespace std;

int main(){
    map <int,int> lista1;
    map <int,int> lista2;
    int numcases;
    int aux;
    int answer;
    int numelements1, numelements2;
    scanf("%d", &numcases);
    for(int i = 1; i <= numcases; i++){
        answer = 0;
        scanf("%d %d", &numelements1, &numelements2);
        for(int j = 1; j <= numelements1; j++){
            scanf("%d", &aux);
            lista1[aux]++;
        }
        for(int j = 1; j <= numelements2; j++){
            scanf("%d", &aux);
            lista2[aux]++;
        }
        for(map<int,int>:: iterator it = lista1.begin(); it != lista1.end(); ++it){
            if(lista2.find(it->first) == lista2.end()){
                answer += it->second;
            }
            else{
                answer += abs(it->second - lista2[it->first]);
            }
        } 
        for(map<int,int>:: iterator it = lista2.begin(); it != lista2.end(); ++it){
            if(lista1.find(it->first) == lista1.end()){
                answer += it->second;
            }
            /*else{
                answer += abs(it->second - lista1[it->first]);
            }*/
        }
        cout << answer << endl;
        lista1.clear();
        lista2.clear();
    }
    return 0;
}
