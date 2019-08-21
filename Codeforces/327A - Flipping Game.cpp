#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 999999
 
using namespace std;
 
typedef long long ll;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int num;
	cin >> num;
	vector<int> digits(num);
	vector<int> pseudo(num);
	for(int i = 0; i < num; i++){
		cin >> digits[i];
		pseudo[i] = digits[i];
	}
	//if(num == 1 && digits[0] == 0)
	//solucao em O(n3)
	int sum = 0;
	int best = 0;
	for(int i = 0; i < num; i++){
		for(int j = 0; j < num; j++){
		    for(int a = i; a <= j; a++){
		        pseudo[a] = 1 - digits[a];
		    }
		    int iguais = 1;
		    for(int i = 0; i < num; i++){
		        if(digits[i] != pseudo[i]) iguais = 0;
		    }
		    if(iguais == 1) continue;
			sum = 0;
			for(int a = 0; a < num; a++){
				sum += pseudo[a];
			}
			for(int a = i; a <= j; a++){
			    pseudo[a] = digits[a];
			}
			best = max(best,sum);
		}
	}
	printf("%d\n", best);
	return 0;
}327
