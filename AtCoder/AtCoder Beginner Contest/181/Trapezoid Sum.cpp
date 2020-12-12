#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll answer = 0;
    ll a, b;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        answer += ((a + b)*(b - a + 1))/2;
    }
    cout << answer << endl;


    return 0;
}
