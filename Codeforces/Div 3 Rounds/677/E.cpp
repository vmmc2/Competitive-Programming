#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll factorial[21];

ll comb(ll n, ll k){
    if(k > n) return 0;

    return (factorial[n])/(factorial[n - k] * factorial[k]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, answer;

    factorial[0] = 1;
    for(int i = 1; i <= 20; i++){
        factorial[i] = i * factorial[i - 1];
    }

    cin >> n;
    answer = (comb(n, n/2) * factorial[n/2 - 1] * factorial[n/2 - 1])/2;
    cout << answer << "\n";

    return 0;
}
