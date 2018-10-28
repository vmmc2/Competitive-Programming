#include <bits/stdc++.h>

using namespace std;

int main(){
    int B, N;
    bool dale;
    int devedor, credor, divida;
    int reserva[25];
    scanf("%d %d", &B, &N);
    while(B){
        dale = true; // a cada caso eu assumo que nao deu merda XD
        for(int i = 1; i <= B; i++){
            scanf("%d", &reserva[i]);
        }
        for(int i = 1; i <= N; i++){
            scanf("%d %d %d", &devedor, &credor, &divida);
            reserva[devedor] -= divida;
            reserva[credor] += divida;
        }
        for(int i = 1; i <= B; i++){
            if(reserva[i] < 0){
                dale = false;
                break;
            }
        }
        if(dale){
            printf("S\n");
        }
        else{
            printf("N\n");
        }
        scanf("%d %d", &B, &N);
    }
    return 0;
}
