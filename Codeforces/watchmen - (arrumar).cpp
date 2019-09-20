#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define INF 9999999
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int comb(int n, int k){
    double res = 1;
    for(int i = 1; i <= k; ++i){
        res = res * (n - k + i) / i;
    }
    return (int)(res + 0.01);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int watchmen;
    cin >> watchmen;
    map<int,int> x;
    map<int,int> y;
    set<pair<int,int>> ss;
    int x0, y0;
    for(int i = 1; i <= watchmen; i++){
        cin >> x0 >> y0;
        if(ss.find({x0,y0}) == ss.end()){
            printf("entrei\n");
            ss.insert({x0,y0});
            x[x0]++;
            y[y0]++;
        }
    }
    ll ans = 0;
    for(map<int,int>::iterator it = x.begin(); it != x.end(); ++it){
        if(it->second >= 2){
            ans += comb(it->second,2)*1LL;
        }
    }
    for(map<int,int>::iterator it = y.begin(); it != y.end(); ++it){
        if(it->second >= 2){
            ans += comb(it->second,2)*1LL;
        }
    }
    cout << ans << "\n";
    return 0;
}
