#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <string.h>
#include <iomanip>

using namespace std;

int main(){
    int qtdnums, qtdqueries;
    vector <int> numeros;
    vector <int> queries;
    int iowa, answer;
    int aux, hope = 1;
    int second;
    while(true){
        scanf("%d", &qtdnums);
        if(qtdnums == 0){
            break;
        }
        for(int i = 1; i <= qtdnums; i++){
            scanf("%d", &aux);
            numeros.push_back(aux);
        }
        scanf("%d", &qtdqueries);
        for(int i = 1; i <= qtdqueries; i++){
            scanf("%d", &aux);
            queries.push_back(aux);
        }
        answer = 99999999;
        printf("Case %d:\n", hope);
        stable_sort(numeros.begin(), numeros.end());
        for(int i = 0; i < (int)queries.size(); i++){
            answer = 99999999;
            for(int j = 0; j < (int)numeros.size(); j++){
                for(int k = j+1; k < (int)numeros.size(); k++){
                    iowa =  numeros[j] + numeros[k];
                    //printf("iowa: %d -- %d\n", iowa, queries[i]);
                    //printf("(queries-iowa): %d\n", abs(queries[i] - iowa));
                    if(fabs(queries[i] - iowa) < answer){
                        //printf("answer: %d\n", answer);
                        answer = fabs(queries[i] - iowa);
                        second = iowa;
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", queries[i], second);
        }
        numeros.clear();
        queries.clear();
        hope++;
    }
    return 0;
}
