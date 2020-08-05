#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll INF = 1e6 + 2;


ll powmod(ll a, ll b){
    ll res = 1;
    while(b){
        if(b % 2) res = (res * a) % MOD;
        a = (a*a) % MOD;
        b /= 2;
    }
    return res;
}

ll inv(ll x){
    return powmod(x, MOD - 2) % MOD;
}

ll choose(ll n, ll r, vector<ll> &fact){
    return (((fact[n] * inv(fact[n - r])) % MOD) * inv(fact[r])) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, a, b;
    ll answer = 0;
    cin >> h >> w >> a >> b;
    
    vector<ll> fact(INF);
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i < INF; i++){
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    
    for(ll i = b + 1; i <= w; i++){
        answer = (answer + choose(h - a - 1 + i - 1, i - 1, fact)*choose(a - 1 + w - i, w - i, fact)) % MOD;
    }
    cout << answer << "\n";
    
    return 0;
}
