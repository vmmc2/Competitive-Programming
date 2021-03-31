#include <bits/stdc++.h>
#include <sstream>
#define MAXN 1005

using namespace std;

void dfs(vector<vector<int>> &adjlist, vector<int> &visited, int source){
  visited[source] = 1;
  for(int i = 0; i < (int)adjlist[source].size(); i++){
    int u = adjlist[source][i];
    if(visited[u] == 0){
      dfs(adjlist, visited, u);
    }
  }
  return;
}

int main() {
  vector<vector<int>> adjlist(MAXN, vector<int>()); //Assumo que o grafo possui todos esses vertices.
  vector<int> visited(MAXN, 0); //Assumo que o grafo possui todos esses vertices.
  int numVertex;
  int a, b;
  cin >> numVertex;

  while(numVertex--){
    cin >> a >> b;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
  }
  int numOfComponents = 0;
  for(int i = 0; i < MAXN; i++){
    if(visited[i] == 0){
      dfs(adjlist, visited, i);
      numOfComponents++;
    }
  }
  cout << "Number of connected components in the graph: " << numOfComponents << "\n";

  return 0;
}
