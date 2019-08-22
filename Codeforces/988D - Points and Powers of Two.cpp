#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define INF 9999999
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
 
	int n;
	cin >> n;
	vector<int> points(n);
	for(int i = 0; i < n; i++){
		cin >> points[i];
	}
	sort(points.begin(), points.end());
	vector<int> answer = {points[0]};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 31; j++){
			int previous = points[i] - (1 << j);
			int next = points[i] + (1 << j);
			bool ls = binary_search(points.begin(), points.end(), previous);
			bool rs = binary_search(points.begin(), points.end(), next);
			if(ls && rs && (int)answer.size() < 3){ //isso quer dizer que eu achei 3 pontos que satisfazem tais condicoes e portanto esse eh o maior subconjunto possivel
				answer = {points[i], previous, next};
			}
			if(ls && (int)answer.size() < 2){
				answer = {points[i], previous};
			}
			if(rs && (int)answer.size() < 2){
				answer = {points[i], next};
			}
		}
	}
	printf("%d\n", (int)answer.size());
	for(auto it: answer){
		printf("%d ", it);
	}
	return 0;
}
