#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    ll sum = 0;
    cin >> n;
    
    vector<int> t(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> t[i];
        sum += t[i];
    }
    
    cin >> m;
    vector<pair<int,int>> p(m);
    for(int i = 0; i < m; i++){
        cin >> p[i].first >> p[i].second;
    }
    
    for(int i = 0; i < m; i++){
        ll aux = sum;
        aux -= t[p[i].first];
        aux += p[i].second;
        cout << aux << endl;
    }
    
    
    return 0;
}
