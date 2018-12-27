#include <bits/stdc++.h>

using namespace std;

int main(){
    int numdevices, numoperations, fuse; // fuse ta em amperes
    vector <int> devices;
    int aux;
    int max;
    int soma;
    int estourou = 0;
    int ligados[20];
    int caso = 1;
    while(true){
        max = - 9999999;
        soma = 0;
        scanf("%d %d %d", &numdevices, &numoperations, &fuse);
        memset(ligados, 0, sizeof(ligados));
        estourou = 0;
        if(numdevices == 0 && numoperations == 0 && fuse == 0){
            break;
        }
        for(int i = 1; i <= numdevices; i++){
            scanf("%d", &aux);
            devices.push_back(aux);
        }
        for(int i = 1; i <= numoperations; i++){
            soma = 0;
            scanf("%d", &aux);
            aux--;
            if(ligados[aux] == 0)
                ligados[aux]++;
            else{
                ligados[aux]--;
            }
            for(int j = 0; j < numdevices; j++){
                if(ligados[j] == 1){
                    soma += devices[j];
                }
            }
            if(soma > max){
                max = soma;
            }
            if(soma > fuse){
               estourou = 1; 
            }
        }
        printf("Sequence %d\n", caso);
        if(estourou == 1){
            printf("Fuse was blown.\n");
        }
        else{
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n", max);
        }
        printf("\n");
        caso++;
        devices.clear();
    }
    return 0;
}
