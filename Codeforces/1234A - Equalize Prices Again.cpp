#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    cin >> numcasos;
    for(int i = 1; i <= numcasos; i++){
        int n;
        cin >> n;
        vector<ll> goods(n);
        ll sum = 0;
        for(int i = 0; i < n; i++){
            cin >> goods[i];
            sum += goods[i];
        }
        ll answer = ceil((double)sum/n);
        cout << answer << "\n";
    }
    return 0;
}
