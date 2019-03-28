#include <bits/stdc++.h>

using namespace std;

vector<int> adjlist[110];
int visitados[110];
vector<int> answer;

void preprocess(){
    for(int i = 0; i < 110; i++){
        adjlist[i].clear();
    }
}

void toposort(int x){
    int u;
    visitados[x] = 1;
    for(int i = 0; i < (int)adjlist[x].size(); i++){
        u = adjlist[x][i];
        if(visitados[u] == 0){
            toposort(u);
        }
    }
    answer.push_back(x);
}

int main(){
    int a, b;
    int numvertices, numedges;
    while(true){
        answer.clear();
        memset(visitados, 0, sizeof visitados);
        preprocess();
        scanf("%d %d", &numvertices, &numedges);
        if(numvertices == 0 && numedges == 0) break;
        for(int i = 0; i < numedges; i++){
            scanf("%d %d", &a, &b);
            adjlist[a].push_back(b);
        }
        for(int i = 1; i <= numvertices; i++){
            if(visitados[i] == 0){
                toposort(i);
            }
        }
        for(int a = (int)answer.size()-1; a >= 1; a--){
            printf("%d ", answer[a]);
        }
        printf("%d\n", answer[0]);
    }
    
    return 0;
}
