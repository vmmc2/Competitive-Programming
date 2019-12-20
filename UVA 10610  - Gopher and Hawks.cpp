#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adjlist[100000];
int visitados[100000];
int dist[100000];
const double eps = 1e-9;

int cmp (double a, double b = 0) { //essa funcao aqui serve para verificar se dois pontos que teoricamente sao diferentes, sao mesmo diferentes...
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}

struct point{
    double x, y;
    bool operator <(const point &p) const { //operator para fazer a comparacao entre pontos...
    if(cmp(x, p.x) != 0) return x < p.x;
    return cmp(y, p.y) < 0;
    }
};

void reset_all(){
    for(int i = 0; i < 100000; i++){
        adjlist[i].clear();
        visitados[i] = 0;
        dist[i] = INF;
    }
    return;
}

bool check(point a, point b, int speed, int tempolimite){
    double dx = (double)abs(a.x - b.x);
    double dy = (double)abs(a.y - b.y);
    double dist = sqrt((dx*dx) + (dy*dy));
    double realtime = (double)(tempolimite*60);
    double tempogasto = double(dist/(double)speed);
    if(tempogasto <= realtime) return true;
    else return false;
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
                fila.push(u);
                dist[u] = min(dist[u], dist[x] + 1);
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int speed, limitetime; //speed = m/s  ------ limitetime = minutos.
    while(cin >> speed >> limitetime){
        if(speed == 0 && limitetime == 0) break;
        map<point,int> dicio;
        vector<point> registro;
        reset_all();
        point start;
        point end;
        double x, y;
        cin >> x >> y;
        start.x = x;
        start.y = y;
        cin >> x >> y;
        end.x = x;
        end.y = y;
        registro.pb(start);
        registro.pb(end);
        cin.ignore();
        string trash;
        point px;
        while(true){
            getline(cin, trash);
            if(trash == "") break;
            stringstream ss(trash);
            ss >> x >> y;
            px.x = x;
            px.y = y;
            registro.pb(px);
        }
        //pronto... morgou....
        //hora de montar o grafo...
        for(int i = 0; i < (int)registro.size(); i++){
            dicio[registro[i]] = i;
        }
        //hora de tentar construir as arestas...
        for(int i = 0; i < (int)registro.size() - 1; i++){
            for(int j = i + 1; j < (int)registro.size(); j++){
                if(check(registro[i], registro[j], speed, limitetime)){
                    adjlist[dicio[registro[i]]].pb(dicio[registro[j]]);
                    adjlist[dicio[registro[j]]].pb(dicio[registro[i]]);
                }
            }
        }
        //arestas construidas...
        //hora de rodas a bfs
        bfs(dicio[start]);
        if(dist[dicio[end]] == INF){
            cout << "No." << "\n";
        }else{
            int answer = (dist[dicio[end]] + 1) - 2;
            cout << "Yes, visiting " << answer << " other holes." << "\n";
        }
    }
    return 0;
}
