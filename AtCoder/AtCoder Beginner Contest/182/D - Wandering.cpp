#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll ans = 0, curr = 0, mx = -1e17, sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        mx = max(mx, sum);
        ans = max(ans, curr + mx);


        curr += sum;

        cout << "curr: " << curr << " mx: " << mx << " ans: " << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
