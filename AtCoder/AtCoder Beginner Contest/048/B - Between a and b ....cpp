#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll n, ll x){
    if(n < 0) return 0;
    return (n/x) + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll a, b, x;
    cin >> a >> b >> x;
    
    cout << f(b, x) - f(a - 1, x) << endl;
    
    
    return 0;
}
