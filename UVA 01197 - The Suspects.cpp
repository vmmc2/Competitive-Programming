#include <bits/stdc++.h>

using namespace std;

int dsu[30100];
int size[30100];

void preprocess(){
    for(int i = 0; i < 30100; i++){
        dsu[i] = i;
        size[i] = 1;
    }
}

int root(int i){
    while(dsu[i] != i){
        dsu[i] = dsu[dsu[i]]; //Aqui eu to aplicando o Path Compressing para a travessia ficar mais
        //eficiente.
        i = dsu[i];
    }
    return i;
}

void weighted_union(int a, int b){
    int root_A = root(a);
    int root_B = root(b);
    if(root_A == root_B){
        return;
    }
    if(size[root_A] < size[root_B]){
        dsu[root_A] = dsu[root_B];
        size[root_B] += size[root_A];
    }
    else{
        dsu[root_B] = dsu[root_A];
        size[root_A] += size[root_B];
    }
}


int main(){
    int numstudents;
    int numgroups;
    int stgroup;
    int raiz;
    int outro;
    int answer;
    while(true){
        scanf("%d %d", &numstudents, &numgroups);
        preprocess();
        answer = 0;
        if(numstudents == 0 && numgroups == 0){
            break;
        }
        for(int i = 1; i <= numgroups; i++){
            scanf("%d", &stgroup);
            scanf("%d", &raiz);
            for(int j = 2; j <= stgroup; j++){
                scanf("%d", &outro);
                weighted_union(raiz, outro);
                //printf("raiz: %d --- outro: %d\n", raiz, outro);
            }
        }
        answer = root(0);
        //printf("asnwer: %d\n", answer);
        printf("%d\n", size[answer]);
    }
    return 0;
}
