#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adjlist[100000];
vector<int> visitados;
vector<int> pred;

void reset(){
    for(int i = 0; i < 100000; i++){
        adjlist[i].clear();
    }
}

void bfs(int source){
    queue<int> fila;
    visitados[source] = 1;
    fila.push(source);
    while(!fila.empty()){
        int x = fila.front();
        fila.pop();
        for(int i = 0; i < (int)adjlist[x].size(); i++){
            int v = adjlist[x][i];
            if(visitados[v] == 0){
                visitados[v] = 1;
                fila.push(v);
                pred[v] = x;
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    cin >> numcasos;
    for(int a = 1; a <= numcasos; a++){
        reset();
        int numedges, numqueries;
        cin >> numedges >> numqueries;
        map<string, int> dicio;
        map<int, string> diciorev;
        int init = 0;
        string x, y;
        for(int b = 1; b <= numedges; b++){
            cin >> x >> y;
            if(dicio.find(x) == dicio.end()){
                dicio[x] = init;
                diciorev[init] = x;
                init++;
            }
            if(dicio.find(y) == dicio.end()){
                dicio[y] = init;
                diciorev[init] = y;
                init++;
            }
            adjlist[dicio[x]].pb(dicio[y]);
            adjlist[dicio[y]].pb(dicio[x]);
        }
        string start, fim;
        for(int b = 1; b <= numqueries; b++){
            cin >> start >> fim;
            
            visitados.clear();
            pred.clear();
            visitados.resize((int)dicio.size(), 0);
            pred.resize((int)dicio.size());
            for(int i = 0; i < (int)pred.size(); i++){
                pred[i] = i;
            }
            
            bfs(dicio[start]);
            //hora de restaurar o path;
            vector<char> path;
            int c;
            for(c = dicio[fim]; c != dicio[start]; c = pred[c]){
                string w = diciorev[c];
                path.push_back(w[0]);
            }
            string l = diciorev[dicio[start]];
            path.push_back(l[0]);
            reverse(path.begin(), path.end());
            for(int i = 0; i < (int)path.size(); i++){
                cout << path[i];
            }
            cout << "\n";
        }
        if(a != numcasos){
            cout << "\n";
        }
    }
    return 0;
}
