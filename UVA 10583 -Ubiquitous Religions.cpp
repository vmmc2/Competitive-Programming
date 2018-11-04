#include <bits/stdc++.h>

using namespace std;

void initialize(int dsu[], int size[]){
    for(int i = 0; i < 500000; i++){
        dsu[i] = i;
        size[i] = 1;
    }
}

int root(int dsu[], int a){
    while(dsu[a] != a){
        dsu[a] = dsu[dsu[a]];
        a = dsu[a];
    }
    return a;
}    

void Union(int dsu[], int size[], int a, int b){
    int root_a = root(dsu, a);
    int root_b = root(dsu, b);
    if(root_a == root_b){
        return;
    }
    if(size[a] < size[b]){
        dsu[root_a] = dsu[root_b];
        size[root_b] += size[root_a];
    }
    else{
        dsu[root_b] = dsu[root_a];
        size[root_a] += size[root_b];
    }
}

int main(){
    int dsu[500000];
    int size[500000];
    int n, m; //n = numero de estudantes, m = numero de relacoes(pares)
    int a, b;
    int answer, x = 1;
    scanf("%d %d", &n, &m);
    while(n != 0 && m != 0){
        initialize(dsu, size);
        answer = n;
        for(int i = 1; i <= m; i++){
            scanf("%d %d", &a, &b);
            if(root(dsu, a) != root(dsu, b)){
                answer--;
            }
            Union(dsu, size, a, b);
        }
        printf("Case %d: %d\n", x, answer);
        x++;
        scanf("%d %d", &n, &m);
    }
    return 0;
}
