#include <bits/stdc++.h>

using namespace std;

int vetor[1000];
int size[1000];

void initialize(int n){
    for(int i = 1; i <= n; i++){ //Indexado na base 1 ate N
        vetor[i] = i;
        size[i] = 1;
    }
}

int root(int i){
    while(vetor[i] != i){
        vetor[i] = vetor[vetor[i]]; //Aqui eu to aplicando o Path Compressing para a travessia ficar mais
        //eficiente.
        i = vetor[i];
    }
    return i;
}

bool find(int a, int b){
    if(root(a) == root(b)){
        return true;
    }
    else{
        return false;
    }
}

void weighted_union(int a, int b){
    int root_A = root(a);
    int root_B = root(b);
    if(size[root_A] < size[root_B]){
        vetor[root_A] = vetor[root_B];
        size[root_B] += size[root_A];
    }
    else{
        vetor[root_B] = vetor[root_A];
        size[root_A] += size[root_B];
    }
}

int main(){
    bool answer;
    int yes, no;
    string s;
    int c, x, y;
    int numcasos, pc;
    scanf("%d", &numcasos);
    while(numcasos--){
        yes = 0;
        no = 0;
        scanf("\n%d\n", &pc);
        initialize(pc);//inicializando o DSU a cada caso de teste
        while(1){
            if(!getline(cin,s) || s.empty()){
                break;
            }
            sscanf(s.c_str(),"%c %d %d", &c, &x, &y);
            if(c == 'c'){
                weighted_union(x,y);
            }
            else if(c == 'q'){
                answer = find(x,y);
                if(answer){
                    yes++;
                }
                else{
                    no++;
                }
            }
        }
        if(numcasos != 1){
            printf("\n");
        }
        printf("%d,%d\n",yes,no);
    }
    return 0;
}
