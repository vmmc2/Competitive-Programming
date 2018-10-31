#include <bits/stdc++.h>

using namespace std;

void initialize(int array[], int size[], int n){
    for(int i = 0; i < n; i++){
        array[i] = i;
        size[i] = 1;
    }
}

int root(int array[], int i){
    while(array[i] != i){
        array[i] = array[array[i]]; //Aqui eu to aplicando o Path Compressing para a travessia ficar mais
        //eficiente.
        i = array[i];
    }
    return i;
}

void weighted_union(int array[], int size[], int a, int b){
    int root_A = root(array, a);
    int root_B = root(array, b);
    if(root_A == root_B){
        return;
    }
    if(size[root_A] < size[root_B]){
        array[root_A] = array[root_B];
        size[root_B] += size[root_A];
    }
    else{
        array[root_B] = array[root_A];
        size[root_A] += size[root_B];
    }
}

int numelements(int array[], int size[], int i){
    int rootI = root(array, i);
    return size[rootI];
}

int main(){
    int maior;
    int array[40000];
    int size[40000];
    int numcasos;
    int n, m; // n = number of citizens and m = number of pairs
    int a, b;
    scanf("%d", &numcasos);
    while(numcasos--){
        maior = -1;
        scanf("%d %d", &n, &m);
        initialize( array, size, n);
        for(int i = 1; i <= m; i++){
            scanf("%d %d", &a, &b);
            weighted_union(array, size, a, b);
        }
        for(int i = 1; i <= n; i++){
            int aux = numelements(array,size,i);
            if(aux > maior){
                maior = aux;
            }
        }
        printf("%d\n", maior);
    }
    return 0;
}
