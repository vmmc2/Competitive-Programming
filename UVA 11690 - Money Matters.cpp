#include <bits/stdc++.h>

using namespace std;

int dsu[100000];
int size[100000];
long long money[100000];
map <int,int> dictionary;// A soma da grana de elementos que estao em um mesmo grupo deve ser igual a 0

void preprocess(){
    for(int i = 0; i < 100000; i++){
        dsu[i] = i; //cada elemento vai ser pai de si mesmo
        size[i] = 1;
        money[i] = 0;
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
        //printf("money(b): %d   --- dict(a): %d\n", money[root_B], dictionary[root_A]);
        money[root_B] += money[root_A];
        money[root_A] = 0;
    }
    else{
        dsu[root_B] = dsu[root_A];
        size[root_A] += size[root_B];
        //printf("money(a): %d   --- dict(b): %d\n", money[root_A], dictionary[root_B]);
        money[root_A] += money[root_B];
        money[root_B] = 0;
    }
}
int num_elements(int x){
    int root_x = root(x);
    return size[root_x];
}

int main(){
    int numcasos;
    int numfriends;
    int numrelations;
    int iowa;
    int flag = 0;
    int pessoa1, pessoa2;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        flag = 0;
        dictionary.clear();
        preprocess();
        int aux = 0;
        scanf("%d %d", &numfriends, &numrelations);
        for(int j = 1; j <= numfriends; j++){
            scanf("%d", &iowa);
            money[aux] = iowa;
            aux++;
        }
        for(int j = 1; j <= numrelations; j++){
            scanf("%d %d", &pessoa1, &pessoa2);
            weigthed_union(pessoa1, pessoa2);
        }
        //printf("Caso %d:\n", i);
        for(int j = 0; j < numfriends; j++){
            //printf("root: %d --- money: %d\n", root(j), money[root(j)]);
            if(money[j] != 0){
                flag = 1;
            }
        }
        //printf("\n\n");
        if(flag == 1){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("POSSIBLE\n");
        }
    }
    return 0;
}
