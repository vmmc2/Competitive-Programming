#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int days = 0;
	int nprob = 1;
	for(int i = 0; i < n; i++){
		if(v[i] == nprob){
		    days++;
		    nprob++;
		}
		if(v[i] > nprob){
		    days++;
		    nprob++;
		}
	}
	cout << days << "\n";
	return 0;
}
