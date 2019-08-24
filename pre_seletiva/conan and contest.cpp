#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 999999
#define pii pair<int,int>

using namespace std;

typedef long long ll;

int main(){
	int numcasos;
	scanf("%d", &numcasos);
	for(int a = 1; a <= numcasos; a++){
		int numproblems, numtimes, numsubmissions;
		scanf("%d %d %d", &numproblems, &numtimes, &numsubmissions);
		pii matrix[numtimes + 1][numproblems + 1] = {{0,0}};
		map<int,pii> firstsolv; //para cada problema guarda o id do time que o resolveu 	primeiro o first eh o id do cara e o second eh o tempo que ele levou
		pii firstcs = {0,5000000}; //id do cara, tempo que ele levou
		pii lastcs = {0,-1};//id do cara tempo que ele levou
		int pid, sid, status, minutes, seconds;
		for(int i = 0; i < numsubmissions; i++){
			scanf("%d %d %d %d:%d", &pid, &sid, &status, &minutes, &seconds);
			//checando o primeiro a submeter uma solucao certa
			if(status == 1){
				int time = (minutes*60);
				time += seconds;
				if(time < firstcs.second){
					firstcs.first = sid;
					firstcs.second = time;
				}
				if(time == firstcs.second){
					if(pid < firstcs.first) firstcs.first = pid;
				}
			}
			//checando o ultimo a submeter uma solucao certa
			if(status == 1){
				int time = (minutes*60);
				time += seconds;
				if(time > lastcs.second){
					lastcs.first = sid;
					lastcs.second = time;
				}
				if(time == lastcs.second){
					if(pid < lastcs.first) lastcs.first = pid;
				}
			}
			//first to solve a specific problem
			if(status == 1){
				int time = (minutes*60);
				time += seconds;
				if(firstsolv.count(pid) == 0){
					firstsolv[pid] = {sid, time};
				}
				else if(firstsolv.count(pid) == 1){
					if(firstsolv[pid].second > time){
						firstsolv[pid] = {sid, time};
					}
					if(fistsolv[pid].second == time && firstsolv[pid].first > sid){
						firstsolv[pid].first = sid;
					}
				}
			}
			//mais uma condicao
			map<int,int> novo;
			for(auto it: firstsolv){
				novo[it.first]++;
			}
			//a ultima
			if(status == 0 || status == 1){
				if(status == 0){
					if(matrix[sid][pid].second == 0){
						matrix[sid][pid].first += 1;
					}
				}
				else if(status == 1){
					if(matrix[sid][pid].second == 0){
						matrix[sid][pid].second = 1;
					}
				}
			}
		}
		for(auto it: firstsolv){
			if(firstsolv.count(it->first) == 0){
				printf("-1 ");
			}
			else printf("%d ", it->second.first);
		}
		printf("\n");
		printf("%d %d %d %d\n",firstcs.first, lastcs.first, );
	}
	return 0;
}
