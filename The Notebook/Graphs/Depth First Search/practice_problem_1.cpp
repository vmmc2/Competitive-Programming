#include <bits/stdc++.h>
#include <sstream>

using namespace std;

void dfs(int source, vector<vector<int>> &adjlist, vector<int> &visited){
	visited[source] = 1;
	for(int i = 0; i < (int)adjlist[source].size(); i++){
		int u = adjlist[source][i];
		if(visited[u] == 0){
			dfs(u, adjlist, visited);
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int vertex, edges;
	int a, b;
	int numComponents = 0;
	cin >> vertex >> edges;

	vector<vector<int>> adjlist(vertex + 1, vector<int>());
	vector<int> visited(vertex + 1, 0);

	while(edges--){
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	for(int i = 1; i <= vertex; i++){
		if(visited[i] == 0){
			dfs(i, adjlist, visited);
			numComponents++;
		}
	}
	cout << numComponents << "\n";
	
	
	return 0;	
}
