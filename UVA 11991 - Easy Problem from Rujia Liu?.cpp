#include <bits/stdc++.h>

using namespace std;

int main(){
    int aux;
    vector <vector<int>> adjlist;
    int n, m; //n = numero de elementos no array; m = numero de queries
    int k, v; // k-esima ocorrencia do elemento v no array
    while(scanf("%d %d", &n, &m) != EOF){
        adjlist.assign(1000000, vector<int>());
        for(int i = 1; i <= n; i++){
            scanf("%d", &aux);
            adjlist[aux].push_back(i);
        }
        for(int j = 1; j <= m; j++){
            scanf("%d %d", &k, &v);
            if(k > adjlist[v].size()){
                printf("0\n");
            }
            else{
                printf("%d\n", adjlist[v][k-1]);
            }
        }
        for(int i = 0; i < 100000; i++){
            adjlist[i].clear();
        }
    }
    return 0;
}
