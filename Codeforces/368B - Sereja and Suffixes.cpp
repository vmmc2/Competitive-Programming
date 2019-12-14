#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define pb push_back
#define INF 99999999
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, aux;
    cin >> n >> m;
    vector<int> v(n);
    vector<ll> sum(n, 0);
    set<int> registro;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = n - 1; i >= 0; i--){
        registro.insert(v[i]);
        sum[i] = (int)registro.size();
    }
    for(int i = 0; i < m; i++){
        cin >> aux;
        aux--;
        cout << sum[aux] << "\n";
    }
    return 0;
}
