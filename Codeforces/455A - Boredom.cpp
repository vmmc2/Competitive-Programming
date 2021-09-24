#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> v(n);
    vector<ll> dp(100001, 0);
    map<ll,ll> counter;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        counter[v[i]]++;
    }
    dp[0] = 0;
    dp[1] = counter[1];
    for(int i = 2; i <= 100000; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + counter[i]*i);
    }

    cout << dp[100000] << endl;

    return 0;
}
