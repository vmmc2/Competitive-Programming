#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos, farmers;
    double size, animals, factor;
    double answer;
    double aux1, aux2, aux3;
    scanf("%d", &numcasos);
    while(numcasos--){
        answer = 0;
        scanf("%d", &farmers);
        for(int i = 1; i <=farmers; i++){
            scanf("%lf %lf %lf", &size, &animals, &factor);
            aux1 = size/animals;
            aux2 = aux1*factor;
            aux3 = (aux2*animals);
            answer += aux3;
        }
        printf("%.0lf\n", answer);
    }
    return 0;
}
