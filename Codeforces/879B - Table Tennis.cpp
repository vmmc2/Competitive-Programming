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
 
	ll n, w;
	cin >> n >> w;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
	    cin >> v[i];
	}
	if(w >= n){
	    cout << n << "\n";
	    return 0;
	}
    int p1 = 0;
    int p2 = 1;
    int wins = 0;
    while(true){
        if(v[p1] > v[p2]){
            p2 = (p2 + 1)%n;
            wins++;
            if(wins == w) break;
        }else{
            wins = 0;
            wins++;
            p1++;
            p2 = (p1 + 1)%n;
        }
    }
    cout << v[p1] << "\n";
	return 0;
}
