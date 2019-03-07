#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int numcasos, i;
    int x1, y1, r1;
    int x2, y2, r2;
    double distancia, modulo;
    scanf("%d", &numcasos);
    for(i = 1; i <= numcasos; i++){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        distancia = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
        modulo = (double) (r1 - r2);
        if(modulo < 0){
            modulo = modulo*(-1);
        }
        if(distancia == modulo){
            printf("E\n");
        }
        else if((distancia == 0) || (distancia >= 0 && distancia < modulo)){
            printf("I\n");
        }
        else{
            printf("O\n");
        }
    }
    return 0;
}
