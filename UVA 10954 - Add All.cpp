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
    while(true){
        cin >> n;
        if(n == 0) break;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll aux;
        for(int i = 0; i < n; i++){
            cin >> aux;
            pq.push(aux);
        }
        ll answer = 0;
        while(pq.size() != 1){
            ll number1 = pq.top();
            pq.pop();
            ll number2 = pq.top();
            pq.pop();
            ll soma = number1 + number2;
            pq.push(soma);
            answer += soma;
        }
        cout << answer << endl;
    }
	return 0;
}
