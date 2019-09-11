#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define INF 9999999
#define pb push_back

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> sum(n, 0);
    int total = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        total += v[i];
    }
    for(int i = 0; i < n; i++){
        if(i == 0) sum[i] = v[i];
        else sum[i] += (sum[i - 1] + v[i]);
    }
    for(int i = 0; i < n; i++){
        int sum1 = sum[i];
        int sum2 = total - sum[i];
        if(sum1 == sum2) ans++;
    }
    cout << ans << "\n";
    return 0;
}
