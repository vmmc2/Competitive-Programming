#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define pb push_back
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adjlist[1000000];
int dist[1000000];
int visited[1000000];

void reset_graph(){
    for(int i = 0; i < 1000000; i++){
        adjlist[i].clear();
    }
    return;
}
void reset_vist(){
    for(int i = 0; i < 1000000; i++){
        visited[i] = 0;
    }
}
void reset_dist(){
    for(int i = 0; i < 1000000; i++){
        dist[i] = INF;
    }
    return;
}

void bfs(int source){
    dist[source] = 0;
    visited[source] = 1;
    queue<int> fila;
    fila.push(source);
    while(!fila.empty()){
        int x = fila.front();
        fila.pop();
        for(int i = 0; i < (int)adjlist[x].size(); i++){
            int v = adjlist[x][i];
            if(visited[v] == 0){
                fila.push(v);
                visited[v] = 1;
                dist[v] = min(dist[v], dist[x] + 1);
            }
        }
    }
    return;
}

int main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    int numv, numedges, queries;
    string aux, aux2;
    cin >> numcasos;
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for(int a = 1; a <= numcasos; a++){
        reset_dist();
        reset_graph();
        reset_vist();
        map<string,int> dicio;
        cin >> numv >> numedges >> queries;
        int inicio = 0;
        for(int i = 0; i < numv; i++){ // fazendo o mapeamento.
            cin >> aux;
            dicio[aux] = inicio;
            inicio++;
        }
        for(int i = 0; i < numedges; i++){ //montando o grafo...
            cin >> aux >> aux2;
            adjlist[dicio[aux]].push_back(dicio[aux2]);
            adjlist[dicio[aux2]].push_back(dicio[aux]);
        }
        printf("DATA SET  %d\n\n", a);
        int size;
        string partida;
        string chegada;
        for(int i = 0; i < queries; i++){
            reset_dist();
            reset_vist();
            cin >> size >> partida >> chegada;
            bfs(dicio[partida]);
            if(dist[dicio[chegada]] != INF){
                printf("$%d\n", size*dist[dicio[chegada]]*100);
            }else{
                printf("NO SHIPMENT POSSIBLE\n");
            }
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
