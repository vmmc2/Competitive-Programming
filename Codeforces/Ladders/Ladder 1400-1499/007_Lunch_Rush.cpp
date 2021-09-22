#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    ll answer = -5e9;

    cin >> n >> k;
    
    vector<pair<ll,ll>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    for(int i = 0; i < n; i++){
        if(v[i].second > k){
            answer = max(answer, v[i].first - (v[i].second - k));
        }else{
            answer = max(answer, v[i].first);
        }
    }

    cout << answer << endl;

    return 0;
}
