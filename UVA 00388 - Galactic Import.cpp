#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adjlist[100];
int visitados[100];
int dist[100];
double highvalues[100];

void reset(){
    for(int i = 0; i < 100; i++){
        adjlist[i].clear();
        visitados[i] = 0;
        dist[i] = INF;
        highvalues[i] = 0.00;
    }
    return;
}

void bfs(int source){
    queue<int> fila;
    visitados[source] = 1;
    dist[source] = 0;
    fila.push(source);
    while(!fila.empty()){
        int x = fila.front();
        fila.pop();
        for(int i = 0; i < (int)adjlist[x].size(); i++){
            int u = adjlist[x][i];
            if(visitados[u] == 0){
                visitados[u] = 1;
                dist[u] = min(dist[u], dist[x] + 1);
                fila.push(u);
            }
        }
    }
    return;
}

double calc(double i, double c){
    double ans = c*pow(1.05, i);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numvertices;
    while(cin >> numvertices){
        reset();
        int init = 0;
        map<char,int> dicio;
        dicio['*'] = init; // '*' -> esse eh o simbolo da terra...
        init++;
        map<char,double> values;
        for(int a = 1; a <= numvertices; a++){
            char planet;
            double val;
            string s;
            cin >> planet >> val >> s;
            if(values.find(planet) == values.end()){
                values[planet] = val;
            }
            if(dicio.find(planet) == dicio.end()){
                dicio[planet] = init;
                init++;
            }
            for(int i = 0; i < (int)s.size(); i++){
                if(dicio.find(s[i]) == dicio.end()){
                    dicio[s[i]] = init;
                    init++;
                }
                adjlist[dicio[planet]].pb(dicio[s[i]]);
            }
        }
        bfs(dicio['*']); //roda a bfs a partir da terra.
        for(map<char,int>::iterator it = dicio.begin(); it != dicio.end(); it++){
            double vv = calc(dist[it->second], values[it->second]);
            highvalues[it->second] = values[it->second] - vv;
        }
        char ans;
        double maximum = -699999;
        for(map<char,int>::iterator it = dicio.begin(); it != dicio.end(); it++){
            if(highvalues[it->second] > maximum){
                maximum = it->second;
                ans = it->first;
            }
        }
        cout << "Import from " << ans << ".\n";
    }
    return 0;
}
