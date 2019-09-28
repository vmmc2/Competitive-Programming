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
 
	int n, t, c;
	int aux;
	cin >> n >> t >> c;
	vector<int> v;
	//mudanca de abordagem para atacar o problema
	//o vector v vai ser responsavel por guardar o indice dos prisioneiros que apresentam um rating >= t
	v.pb(-1); //isso aqui eh pro caso do vector ja comecar com um valor <= t
	for(int i = 0; i < n; i++){
		cin >> aux;
		if(aux > t) v.pb(i);
	}
	v.pb(n); // pra eu ter um parametro no final
	int answer = 0;
	for(int i = 1; i < (int)v.size(); i++){
		int l = v[i] - v[i - 1] - 1;
		answer += max(l - c + 1, 0);
	}
	cout << answer << "\n";
	return 0;
}
