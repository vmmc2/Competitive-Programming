#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define INF 9999999
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> sum(n);
    vector<ll> rsum(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        if(i == 0) sum[i] = v[i];
        else sum[i] += (sum[i - 1] + v[i]);
    }
    for(int i = n - 1; i >= 0; i--){
        if(i == n - 1) rsum[i] = v[i];
        else rsum[i] += (rsum[i + 1] + v[i]);
    }
    int low = 0;
    int high = n - 1;
    int deubosta = 1;
    ll maxsum = -9999999999;
    while(low < high){
        if(sum[low] == rsum[high]){
            maxsum = max(maxsum, sum[low]);
            deubosta = 0;
            low++;
            high--;
        }
        else if(sum[low] < rsum[high]){
            low++;
        }
        else if(sum[low] > rsum[high]){
            high--;
        }
    }
    if(deubosta == 1) cout << "0" << "\n";
    else cout << maxsum << "\n";
    return 0;
}
