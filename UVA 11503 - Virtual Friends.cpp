#include <bits/stdc++.h>

using namespace std;

int dsu[100000];
int size[100000];

void preprocess(){
    for(int i = 0; i < 100000; i++){
        dsu[i] = i; //cada elemento vai ser pai de si mesmo
        size[i] = 1;
    }
}

int root(int x){
    while(dsu[x] != x){
        dsu[x] = dsu[dsu[x]];
        x = dsu[x];
    }
    return x;
}

bool find(int a, int b){
    if(root(a) == root(b)){
        return true;
    }
    else{
        return false;
    }
}

void weigthed_union(int a, int b){
    int root_A = root(a);
    int root_B = root(b);
    if(root_A == root_B){
        return;
    }
    if(size[root_A] <= size[root_B]){
        dsu[root_A] = dsu[root_B];
        size[root_B] += size[root_A];
    }
    else{
        dsu[root_B] = dsu[root_A];
        size[root_A] += size[root_B];
    }
}
int num_elements(int x){
    int root_x = root(x);
    return size[root_x];
}

int main(){
    int numcasos;
    map <string, int> dictionary;
    int numrelations;
    string nome1, nome2;
    int aux;
    scanf("%d", &numcasos);
    for(int i = 1 ; i <= numcasos; i++){
        dictionary.clear();
        preprocess();
        aux = 1;
        scanf("%d", &numrelations);
        for(int j = 1; j <= numrelations; j++){
            cin >> nome1 >> nome2;
            if(dictionary.find(nome1) == dictionary.end()){
                dictionary[nome1] = aux;
                aux++;
            }
            if(dictionary.find(nome2) == dictionary.end()){
                dictionary[nome2] = aux;
                aux++;
            }
            weigthed_union(dictionary[nome1], dictionary[nome2]);
            printf("%d\n", num_elements(dictionary[nome1]));
        }
    }
    return 0;
}
