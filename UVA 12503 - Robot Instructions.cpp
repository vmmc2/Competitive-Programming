#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos;
    int numcomands;
    char comando[50];
    int positions[110];
    int aux;
    int origem;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        origem = 0;
        memset(positions, 0, 106);
        scanf("%d", &numcomands);
        for(int j = 0; j < numcomands; j++){
            scanf(" %[^\n]", comando);
            if(comando[0] == 'L'){
                positions[j] = -1;
                origem--;
            }
            else if(comando[0] == 'R'){
                positions[j] = 1;
                origem++;
            }
            else{
                sscanf(comando+8, "%d", &aux);
                positions[j] = positions[aux-1];
                origem += positions[j];
            }
        }    
        printf("%d\n", origem);
    }
    return 0;
}
