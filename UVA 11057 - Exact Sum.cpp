#include <bits/stdc++.h>

using namespace std;

int main(){
	int books;
	int quantia;
	string lixeira;
	int i;
	int vetor[10000];
	int sum41;
	while(scanf("%d", &books) != EOF){
		vector<pair<int,int>> solutions;
		for(i = 0; i < books; i++){
			scanf("%d", &vetor[i]);
		}
		sort(vetor, vetor+books);
		cin >> quantia;
		int left = 0, right = books - 1;
		while(left < right){
			if(vetor[left] + vetor[right] == quantia){
				solutions.push_back(make_pair(vetor[left],vetor[right]));
				right--;
			}
			else if(vetor[left]+vetor[right] > quantia){
				right--;
			}
			else if(vetor[left]+vetor[right] < quantia){
				left++;
			}
		}
		pair<int,int>bolsonaro;
		bolsonaro.first = solutions[0].first;
		bolsonaro.second = solutions[0].second;
		sum41 = abs(bolsonaro.first - bolsonaro.second);
		for(i = 1; i < solutions.size(); i++){
			if(abs(solutions[i].first - solutions[i].second) < sum41){
				sum41 = abs(solutions[i].first - solutions[i].second);
				bolsonaro.first = solutions[i].first;
				bolsonaro.second = solutions[i].second;
			}
		}
		cout << "Peter should buy books whose prices are " << bolsonaro.first << " and " << bolsonaro.second << ".\n";
		cout << endl;	
	}
	return 0;
}
