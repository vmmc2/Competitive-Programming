#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	int a = 0, b = 0;
	int contador = 0;
	cin >> n >> m;
	for(a = 0; a <= 1000; a++){
		for(b = 0; b <= 1000; b++){
			if( (a*a) + b == n ){
				if( a + (b*b) == m ){
					contador++;
				}
			}
		}
	}
	cout << contador << endl;
	return 0;
}
