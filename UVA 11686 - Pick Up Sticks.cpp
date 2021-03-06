#include <bits/stdc++.h>

using namespace std;

vector <int> adjlist[1000005];
int visitados[1000005];
int possible = 1;
vector <int> answer;

void preprocess(){
    for(int i = 0; i < 1000005; i++){
        adjlist[i].clear();
    }
}

void toposort(int x){
    if(possible == 0){
        return;
    }
    visitados[x] = 1;
    for(int i = 0; i < (int)adjlist[x].size(); i++){
        int u = adjlist[x][i];
        if(visitados[u] == 0){
            toposort(u);
        }else if(visitados[u] == 1){
            possible = 0;
        }
    }
    answer.push_back(x);
    visitados[x] = 2;
}

int main(){
    int a, b;
    int numvertices, numedges;
    while(true){
        answer.clear();
        possible = 1;
        preprocess();
        memset(visitados, 0, sizeof visitados);
        scanf("%d %d", &numvertices, &numedges);
        if(numvertices == 0 && numedges == 0){
            break;
        }
        for(int i = 0; i < numedges; i++){
            scanf("%d %d", &a, &b);
            adjlist[a].push_back(b);
        }
        for(int i = 1; i <= numvertices; i++){
            if(visitados[i] == 0){
                toposort(i);
            }
        }
        if(possible == 0){
            printf("IMPOSSIBLE\n");
        }else{
            for(int a = answer.size() - 1; a >= 0; a--){
                printf("%d\n", answer[a]);
            }
        }
    }
    return 0;
}
