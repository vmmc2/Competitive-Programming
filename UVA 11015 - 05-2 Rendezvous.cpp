#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    int numvertices, numedges;
    int deonde, paraonde, weight;
    string nome;
    int caso = 1;
    string dale;
    while(scanf("%d %d", &numvertices, &numedges) == 2 && numvertices != 0){
        map<string,int> dicionary;
        map<int,string>dicio2;
        int aux = 1;
        int graph[23][23];
        for(int i = 0; i < 23; i++){
            for(int j = 0; j < 23; j++){
                graph[i][j] = 100000000;
            }
            graph[i][i] = 0;
        }
        for(int i = 1; i <= numvertices; i++){
            cin >> nome;
            if(dicionary.find(nome) == dicionary.end()){
                dicionary[nome] = aux;
                dicio2[aux] = nome;
                aux++;
            }
        }
        //le agora as arestas
        for(int i = 1; i <= numedges; i++){
            scanf("%d %d %d", &deonde, &paraonde, &weight);
            graph[deonde][paraonde] = graph[paraonde][deonde] = min(graph[deonde][paraonde], weight);
        }
        //roda o floyd-warshall
        for(int k = 1; k <= numvertices; k++){
            for(int i = 1; i <= numvertices; i++){
                for(int j = 1; j <= numvertices; j++){
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        int desgraca = 100000000;
        int sum = 0;
        for(int i = 1; i <=numvertices; i++){
            sum = 0;
            for(int j = 1; j <= numvertices; j++){
                sum += graph[i][j];
            }
            if(sum < desgraca){
                desgraca = sum;
                dale = dicio2[i];;
            }
        }
        cout << "Case #" << caso << " : " << dale << endl;
        caso++;
    }
    return 0;
}
