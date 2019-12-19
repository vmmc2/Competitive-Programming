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
int dist[100000];

void reset_all(){
    for(int i = 0; i < 100000; i++){
        adjlist[i].clear();
        visitados[i] = 0;
        dist[i] = INF;
    }
    return;
}

void reset_disvis(){
    for(int i = 0; i < 100000; i++){
        visitados[i] = 0;
        dist[i] = INF;
    }
    return;
}

bool check(string a, string b){
    if((int)a.size() != (int)b.size()){
        return false;
    }else{
        int count = 0;
        for(int i = 0; i < (int)a.size(); i++){
            if(a[i] != b[i]) count++;
        }
        if(count == 1) return true;
        else return false;
    }
}

void bfs(int source, int dest){
    queue<int> fila;
    visitados[source] = 1;
    dist[source] = 0;
    fila.push(source);
    while(!fila.empty()){
        int x = fila.front();
        fila.pop();
        for(int i = 0; i < (int)adjlist[x].size(); i++){
            int v = adjlist[x][i];
            if(visitados[v] == 0){
                visitados[v] = 1;
                dist[v] = min(dist[v], dist[x] + 1);
                fila.push(v);
                if(v == dest) return;
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
        reset_all();
        vector<string> registro;
        map<string,int> dicio;
        map<int,string> diciorev;
        int init = 0;
        string x;
        while(true){
            cin >> x;
            if(x == "*") break;
            if(dicio.find(x) == dicio.end()){
                dicio[x] = init;
                diciorev[init] = x;
                init++;
                registro.pb(x);
            }
        }
        //hora de modelar o grafo...
        for(int i = 0; i < (int)registro.size() - 1; i++){
            for(int j = i + 1; j < (int)registro.size(); j++){
                if(check(registro[i], registro[j])){
                    adjlist[dicio[registro[i]]].pb(dicio[registro[j]]);
                    adjlist[dicio[registro[j]]].pb(dicio[registro[i]]);
                }
            }
        }
        cin.ignore();
        //processa as queries agr...
        while(true){
            string lixeira;
            string a, b;
            getline(cin, lixeira);
            if(lixeira == "") break;
            stringstream ss(lixeira);
            ss >> a >> b;
            reset_disvis();
            bfs(dicio[a], dicio[b]);
            cout << a << " " << b << " " << dist[dicio[b]] << "\n";
        }
        if(a != numcasos){
            cout << "\n";
        }
    }
    return 0;
}
