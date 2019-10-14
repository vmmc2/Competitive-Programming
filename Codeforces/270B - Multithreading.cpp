#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int x = n - 1;
    int ans = n;
    while(x >= 0 && v[x - 1] < v[x]){
        x--;
    }
    cout << x << "\n";
    return 0;
}
