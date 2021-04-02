#include <bits/stdc++.h>
#include <sstream>

using namespace std;

void dfs(int source, vector<vector<int>> &adjlist, vector<int> &dist, vector<bool> &visited){
	visited[source] = true;
	for(int i = 0; i < (int)adjlist[source].size(); i++){
		int u = adjlist[source][i];
		if(visited[u] == false){
			dist[u] = dist[source] + 1;
			dfs(u, adjlist, dist, visited);
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	int a, b;
	cin >> n;
	vector<vector<int>> adjlist(n + 1, vector<int>());
	vector<bool> visited(n + 1, false);
	vector<int> dist(n + 1, 0);
	vector<bool> isThereAGirl(n + 1, false);
	for(int i = 1; i <= n - 1; i++){
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	cin >> q;
	while(q--){
		cin >> a;
		isThereAGirl[a] = true;
	}
	dfs(1, adjlist, dist, visited);
	int answer = 0, minDist = 1e5;
	for(int i = 1; i <= n; i++){
		if(isThereAGirl[i] == true){
			if(dist[i] < minDist){
				minDist = dist[i];
				answer = i;
			}
		}
	}
	cout << answer << "\n";

	return 0;
}
