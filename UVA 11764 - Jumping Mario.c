#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int numcasos, i, tam;
    int low, high;
    int walls[51];
    scanf("%d", &numcasos);
    for(i = 1; i <= numcasos; i++){
        low = 0;
        high = 0;
        scanf("%d", &tam);
        for(int j = 0; j < tam; j++){
            scanf("%d", &walls[j]);
        }
        if(tam == 1){
            printf("Case %d: 0 0\n", i);
            continue;
        }
        for(int j = 0; j < tam-1; j++){
            if(walls[j] < walls[j+1]){
                high++;
            }
            else if(walls[j] > walls[j+1]){
                low++;
            }
        }
        printf("Case %d: %d %d\n", i, high, low);
    }
    return 0;
}
