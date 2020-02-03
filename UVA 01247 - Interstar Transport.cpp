#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

int adjmat[27][27];
int p[27][27];
map<char,pair<int,char>> dicio;
map<int,char> dicio2;
vector<char> path;

void init(){
	for(int i = 0; i < 27; i++){
		for(int j = 0; j < 27; j++){
			adjmat[i][j] = INF;
			p[i][j] = i;
		}
	}
	return;
}

void floyd_warshall(){
	for(int k = 0; k < 27; k++){
		for(int i = 0; i < 27; i++){
			for(int j = 0; j < 27; j++){
				if(adjmat[i][k] + adjmat[k][j] < adjmat[i][j]){
					adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
					p[i][j] = p[k][j];
				}
			}
		}
	}
	return;
}

void printPath(int i, int j){
	if(i != j) printPath(i, p[i][j]);
	path.push_back(dicio2[j]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int numvertices, numedges;
	for(int i = 0; i < 26; i++){
		dicio[(char)((int)'A' + i)] = {i, (char)('A' + i)};
		dicio2[i] = (char)('A' + i);
	}
	init();

	cin >> numvertices >> numedges;
	char a, b;
	int weight;
	for(int i = 1; i <= numedges; i++){
		cin >> a >> b >> weight;
		adjmat[dicio[a].first][dicio[b].first] = weight;
		adjmat[dicio[b].first][dicio[a].first] = weight;
	}
	floyd_warshall();
	/*
	for(int i = 0; i < 5; i++){
	    for(int j = 0; j < 5; j++){
	        cout << adjmat[i][j] << " ";
	    }
	    cout << "\n";
	}
	cout << "\n\n";
	for(int i = 0; i < 5; i++){
	    for(int j = 0; j < 5; j++){
	        cout << p[i][j] << " ";
	    }
	    cout << "\n";
	}
	*/
	int numqueries;
	cin >> numqueries;
	char from, to;
	for(int i = 1; i <= numqueries; i++){
		cin >> from >> to;
		printPath(dicio[from].first, dicio[to].first);
		for(int j = 0; j < (int)path.size(); j++){
		    if(j != (int)path.size() - 1){
		        cout << path[j] << " ";
		    }else{
		        cout << path[j];
		    }
		}
		path.clear();
		cout << "\n";
	}

	return 0;
}
