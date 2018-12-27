#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int contadorM;
    int contadorF;
    int rF, rM;
    int numcases;
    int i , j;
    char track[1000000];
    scanf("%d", &numcases);
    for(i = 1; i <= numcases; i++){
        scanf(" %[^\n]", track);
        int it = 0;
        contadorM = 0;
        contadorF = 0;
        rF = 0, rM = 0;
        for(j = 0; j < strlen(track); j++){
            if(track[j] != ' '){
                if(track[j] == 'M')contadorM++;
                else contadorF++;
                
                if(track[j+1] == 'M') rM++;
                else rF++;
                
                j++;
                it++;
            }
        }
        if((contadorF == rM || contadorM == rF) && it > 1){
            printf("LOOP\n");
        }
        else{
            printf("NO LOOP\n");
        }
    }
    return 0;
}
