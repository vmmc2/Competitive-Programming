#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adjlist[100000];
int visitados[100000];
int pred[100000];

void reset(){
    for(int i = 0; i < 100000; i++){
        adjlist[i].clear();
        visitados[i] = 0;
        pred[i] = i;
    }
    return;
}

void bfs(int source, int dest){
    queue<int> fila;
    visitados[source] = 1;
    fila.push(source);
    while(!fila.empty()){
        int x = fila.front();
        fila.pop();
        for(int i = 0; i < (int)adjlist[x].size(); i++){
            int u = adjlist[x][i];
            if(visitados[u] == 0){
                visitados[u] = 1;
                fila.push(u);
                pred[u] = x;
            }
            if(u == dest){
                return; //chegamos ao destino...
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numedges;
    int flag = 0;
    while(cin >> numedges){
        reset();
        if(flag == 1){
            cout << "\n";
        }
        map<string,int> dicio;
        map<int,string> diciorev;
        string a, b;
        int init = 0;
        for(int i = 0; i < numedges; i++){
            cin >> a >> b;
            if(dicio.find(a) == dicio.end()){
                dicio[a] = init;
                diciorev[init] = a;
                init++;
            }
            if(dicio.find(b) == dicio.end()){
                dicio[b] = init;
                diciorev[init] = b;
                init++;
            }
            adjlist[dicio[a]].push_back(dicio[b]);
            adjlist[dicio[b]].push_back(dicio[a]);
        }
        string source, dest;
        cin >> source >> dest;
        if(dicio.find(source) == dicio.end()){
            dicio[source] = init;
            diciorev[init] = source;
            init++;
        }
        if(dicio.find(dest) == dicio.end()){
            dicio[dest] = init;
            diciorev[init] = dest;
            init++;
        }
        bfs(dicio[source], dicio[dest]);
        if(visitados[dicio[dest]] == 0){
            cout << "No route\n";
        }else{
            //restaurando o path...
            vector<string> path;
            int c;
            for(c = dicio[dest]; c != dicio[source]; c = pred[c]){
                path.push_back(diciorev[c]);
            }
            path.push_back(diciorev[dicio[source]]);
            reverse(path.begin(), path.end());
            for(int i = 0; i < (int)path.size() - 1; i++){
                cout << path[i] << " " << path[i + 1] << "\n";
            }
        }
        flag = 1;
    }
    return 0;
}
