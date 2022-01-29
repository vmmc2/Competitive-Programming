#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    vector<ll> dp(n, 0);
    ll max1 = -1e10, left1 = -1;
    ll max2 = -1e10, left2 = -1;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i == 0) dp[i] = v[i];
        else dp[i] = dp[i - 1] + v[i];
    }
    int curl = 0, curr = k - 1;
    while(curr < n){
        if(){

        }else{

        }
        curl++, curr++;
    }
    int curl = 0, curr = k - 1;
 
    return 0;
}
