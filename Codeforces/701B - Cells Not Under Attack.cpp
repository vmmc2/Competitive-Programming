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

	ll n, rooks;
	cin >> n >> rooks;
	ll ncells = n*n;
	ll total = 0;
	set<int> lin;
	set<int> col;
	int x, y;
	for(int i = 1; i <= rooks; i++){
		cin >> x >> y;
		total = 0;
		ll ocupadas;
		int flagjafoix = 0;
		int flagjafoiy = 0;
		if(lin.find(x) != lin.end()){
			flagjafoix = 1;
		}else{
			lin.insert(x);
		}
		if(col.find(y) != col.end()){
		    flagjafoiy = 1;
		}else{
			col.insert(y);
		}
		if(flagjafoix == 0 && flagjafoiy == 0){
		    if(i == 1){
		        ocupadas = (2*n - 1);
		    }else{
			    ocupadas = (2*n - 1) - ((int)lin.size()-1) - ((int)col.size() - 1);
		    }
		}else if(flagjafoix == 1 && flagjafoiy == 0){
			ocupadas = (2*n - 1) - n - ((int)lin.size() - 1);
		}else if(flagjafoix == 0 && flagjafoiy == 1){
			ocupadas = (2*n - 1) - n - ((int)col.size() - 1);
		}else if(flagjafoix == 1 && flagjafoiy == 1){
		    ocupadas = 0; //nesse caso, temos que estamos inserindo a peça exatamente na intersecção das linhas formadas por duas peças.
		}
	    total += ocupadas;
	    
	    ncells -= total;
		cout << ncells << " ";
	}
	return 0;
}
