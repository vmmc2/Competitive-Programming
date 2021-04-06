#include <bits/stdc++.h>
#include <sstream>

using namespace std;

//////////////////////////// Teste de Grafo Bipartido (Bigrafo) //////////////////////////////
// Oq eh um grafo bipartido afinal? Um grafo bipartido eh aquele grafo cujos vertices podem //
// ser divididos em dois conjuntos de vertices disjuntos tais que:                          //
// 1) Cada vertice do grafo pertence a apenas um desses 2 conjuntos.                        //
// 2) Cada aresta do grafo conecta vertices de dois conjuntos diferentes.                   //
//////////////////////////////////////////////////////////////////////////////////////////////

bool dfsCheckBipartite(int source, int color, vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> &colors){
  visited[source] = 1;
  colors[source] = color;
  for(int i = 0; i < (int)adjlist[source].size(); i++){
    int u = adjlist[source][i];
    if(visited[u] == false){
      if(dfs(u, color ^ 1, adjlist, visited, colors) == false) return false;
    }else{
      if(colors[source] == colors[u]) return false;
    }
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  vector<<vector<int>> adjlist(20, vector<int>());
  vector<bool> visited(20, false);
  vector<int> colors(20, -1);
  int a, b;
  int edges = 13;
  
  for(int i = 0; i < 13; i++){
    cin >> a >> b;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
  }
  if(dfsCheckBipartite(0, 0, adjlist, visited, colors) == true){
    cout << "Grafo eh bipartido" << "\n";
  }else{
    cout << "Grafo nao eh bipartido" << "\n";
  }
  
  return 0;
}
