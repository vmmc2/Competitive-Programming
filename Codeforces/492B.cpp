#include <bits/stdc++.h>

using namespace std;

int main (){
    int vetor[1050];
    long long lanterns, lengthstreet;
    int i;
    int first = 0, last = 0;
    double radius = -1;
    double answer = -1;
    scanf("%lld %lld", &lanterns, &lengthstreet);
    for(i = 0; i < lanterns; i++){
        scanf("%d", &vetor[i]);
    }
    // 0   2    5   66   78 90
    sort(vetor,vetor+lanterns);
    if(vetor[0] != 0){
        radius = vetor[0] - 0;
        if(radius > answer){
            answer = radius;
        }
    }        
    for(i = 0; i <= lanterns-2; i++){
        radius = vetor[i+1]- vetor[i];
        radius = radius/2;
        if(radius > answer){
            answer = radius;
        }
    }
    if(vetor[lanterns-1] != lengthstreet){
        radius = lengthstreet - vetor[lanterns-1];
        //printf("radius eh : %d\n", radius);
        if(radius > answer){
            answer = radius;
        }
    }
    printf("%.10f\n", answer);
    return 0;
}
