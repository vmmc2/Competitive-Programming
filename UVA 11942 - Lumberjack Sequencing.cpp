#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos;
    int flagcres = 1;
    int flagdescres = 1;
    int beards[10];
    int aux[10];
    scanf("%d", &numcasos);
    printf("Lumberjacks:\n");
    while(numcasos--){
        flagcres = 1;
        flagdescres = 1;
        for(int i = 0; i < 10; i++){
            scanf("%d", &beards[i]);
            aux[i] = beards[i];
        }
        sort(aux, aux+10);//dando o sort em ordem crescente
        for(int i = 0; i < 10; i++){
            if(beards[i] != aux[i]){
                flagcres = 0;
            }
        }
        sort(aux, aux+10, greater<int>());
        for(int i = 0; i < 10; i++){
            if(beards[i] != aux[i]){
                flagdescres = 0;
            }
        }
        if(flagcres == 0 && flagdescres == 0){
            printf("Unordered\n");
        }
        else{
            printf("Ordered\n");
        }
    }
    return 0;
}
