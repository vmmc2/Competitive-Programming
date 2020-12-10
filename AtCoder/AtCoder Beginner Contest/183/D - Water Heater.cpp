#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int s, t, p;
    ll w;
    bool can = true;

    cin >> n >> w;

    vector<ll> v(3e5, 0);
    for(int i = 0; i < n; i++){
        cin >> s >> t >> p;
        v[s] += p;
        v[t] -= p;
    }

    for(int i = 1 ; i < (int)v.size(); i++){
        v[i] += v[i - 1];
    }
    ll ans = v[0];
    for(int i = 0; i < (int)v.size(); i++){
        ans = max(ans, v[i]);
        if(ans > w){
            can = false;
            break;
        }
    }
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
