#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define INF 999999
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool compare(string a, string b){
	return (int)a.size() < (int)b.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> frases(n);
	for(int i = 0; i < n; i++){
		cin >> frases[i];
	}
	int flag = 1;
	sort(frases.begin(), frases.end(), compare);
	for(int i = 1; i <= n - 1; i++){
		flag = 1;
		for(int j = 0; j <= i - 1; j++){
			int dale = frases[i].find(frases[j]);
			if(dale == std::string::npos){
				flag = 0;
				cout << "NO" << "\n";
				return 0;
			}
		}
	}
	cout << "YES" << "\n";
	for(int i = 0; i < n; i++){
		cout << frases[i] << "\n";
	}

	return 0;
}
