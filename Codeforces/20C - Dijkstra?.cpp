#include <bits/stdc++.h>
#include <cmath>
#define INF 2e18
#define pb push_back
#define pii pair<long long, long long>
 
using namespace std;
 
vector <pair<int,long long>> adjlist[200200];
vector <long long> dist;
vector<int> p;
int numvertices;
 
void preprocess(){
    for(int i = 0; i < 200200; i++){
        adjlist[i].clear();
    }
}
 
void dijkstra(int s){
    p.assign(numvertices + 1, -1);
    dist.assign(numvertices + 1, INF);
    dist[s] = 0;
    priority_queue <pii, vector<pii>, greater<pii>> heap;
    heap.push({0,s});
    while(!heap.empty()){
        pii front = heap.top();
        heap.pop();
        int d = front.first, u = front.second;
        if(d > dist[u]){
            continue;
        }
        for(int j = 0; j < (int)adjlist[u].size(); j++){
            pii v = adjlist[u][j];
            if(dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                heap.push({dist[v.first], v.first});
                p[v.first] = u;
            }
        }
    }
}
 
int main(){
    int numedges; //vertices estao rotulados de 1 ate n 
    int a, b, weight;
    vector<int>path;
    scanf("%d %d", &numvertices, &numedges);
    preprocess();
    for(int i = 1; i <= numedges; i++){
        scanf("%d %d %d", &a, &b, &weight);
        adjlist[a].pb({b, weight});
        adjlist[b].pb({a, weight});
    }
    dijkstra(1);
    if(dist[numvertices] == INF){
        printf("-1");
    }
    else{
        for(int v = numvertices; v != 1; v = p[v]){
            path.pb(v);
        }
        path.pb(1);
        reverse(path.begin(), path.end());
        for(int i = 0; i < (int)path.size(); i++){
            printf("%d ", path[i]);
        }
    }
    return 0;
}
