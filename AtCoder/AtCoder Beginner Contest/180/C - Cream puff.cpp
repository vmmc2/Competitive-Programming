#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    vector<ll> answer;

    cin >> n;

    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(i == n/i){
                answer.push_back(i);
            }else{
                answer.push_back(i);
                answer.push_back(n/i);
            }
        }
    }
    sort(answer.begin(), answer.end());
    for(auto x : answer) cout << x << endl;

    return 0;
}
