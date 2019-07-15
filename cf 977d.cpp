#include <bits/stdc++.h>
#include <cmath>
#define INF 0xffffff
#define pb push_back

using namespace std;

vector<long long> adjlist[110]; //grafo
map<int,long long> mask;
map<long long,int> reversemask;
int visitados[110];
vector<long long> answer;

void dfs(int x){
    visitados[x] = 1;
    answer.pb(mask[x]);
    for(int i = 0; i < (int)adjlist[i].size(); i++){
        int u = adjlist[x][i];
        if(visitados[u] == 0){
            dfs(u);
        }
    }
}

int main(){
    int numvertices;
    int partida;
    long long aux;
    vector<long long> registro;
    memset(visitados, 0, sizeof visitados);
    scanf("%d", &numvertices);
    for(int i = 0; i < numvertices; i++){
        scanf("%lld", &aux);
        registro.pb(aux);
    }
    for(int i = 0; i < numvertices; i++){
        mask[i] = registro[i];
        reversemask[registro[i]] = i;
    }
    for(int i = 0; i < numvertices - 1; i++){
        for(int j = i + 1; j < numvertices; j++){
            if(registro[i]/3 == registro[j] || registro[j]/3 == registro[i] || registro[i]*2 == registro[j] || registro[j]*2 == registro[i]){
                adjlist[reversemask[registro[i]]].pb(reversemask[registro[j]]);
                adjlist[reversemask[registro[j]]].pb(reversemask[registro[i]]);
            }
        }
    }
    //grafo montado
    for(int i = 0; i < numvertices; i++){
        if((int)adjlist[i].size() == 1){//ou eh o inicio do grafo ou o final!!
            int y = adjlist[i][0];
            if(mask[i]*2 == mask[y] || mask[i]/3 == mask[y]){
                partida = i;
                break;
            }
        }
    }
    printf("%d\n", partida);
    dfs(partida);
    for(int i = 0; i < numvertices; i++){
        printf("%d: ", i);
        for(int j = 0; j <(int)adjlist[i].size(); j++){
            printf("%d ", adjlist[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < (int)answer.size(); i++){
        printf("%lld ", answer[i]);
    }
    return 0;
}
