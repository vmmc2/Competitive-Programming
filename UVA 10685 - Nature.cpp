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
    int j, k;
    int array[50000];
    int size[50000];
    string aux;
    string animal1, animal2;
    int maior;
    int numcasos;
    int dale;
    map <string,int> dictionary;
    int c, r; //c = creatures and r = relations
    while(1){
        maior = -1;
        scanf("%d %d", &c, &r);
        if(c == 0 && r == 0){
            break;
        }
        initialize(array,size, c);
        for(int i = 1; i <= c; i++){
            cin >> aux;
            dictionary[aux] = i;
            array[i] = i;
            size[i] = 1;
        }
        for(int i = 1; i <= r; i++){
            cin >> animal1 >> animal2;
            j = dictionary[animal1];
            k = dictionary[animal2];
            weighted_union(array,size,j,k);
        }
        for(int i = 1; i <= c; i++){
            dale = numelements(array,size,i);
            if(dale > maior){
                maior = dale;
            }
        }
        printf("%d\n", maior);
    }
    return 0;
}
