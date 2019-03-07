#include <bits/stdc++.h>

using namespace std;

int main(){
    int tamanho; // vai guardar o tamanho dos meus arrays
    long long int *A, *B, *C, *D;
    long long int *SomaAB;
    int i, j, aux;
    int indiceaux = 0;
    long long int contador = 0;
    int halo;
    pair <long long int*,long long int*> bounds;
    scanf("%d", &tamanho);
    A = (long long int *)malloc(tamanho*sizeof(long long int));
    B = (long long int *)malloc(tamanho*sizeof(long long int));
    C = (long long int *)malloc(tamanho*sizeof(long long int));
    D = (long long int *)malloc(tamanho*sizeof(long long int));
    for(i = 0; i < tamanho; i++){
        scanf("%lld %lld %lld %lld", &A[i], &B[i], &C[i], &D[i]);
    }
    aux = tamanho*tamanho;
    SomaAB = (long long int *)malloc(sizeof(long long int)*aux);
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            SomaAB[indiceaux] = A[i] + B[j];
            indiceaux++;
        }
    }
    indiceaux = 0;
    sort(SomaAB, SomaAB+aux);
    for(int k = 0; k < tamanho; k++){
        for(int l = 0; l < tamanho; l++){
            halo = -C[k]-D[l];
            bounds = equal_range(SomaAB, SomaAB+aux, halo);
            contador += bounds.second - bounds.first;
        }
    }
    printf("%d\n", contador);

    return 0;
}
