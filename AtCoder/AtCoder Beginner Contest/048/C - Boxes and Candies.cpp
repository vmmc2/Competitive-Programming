#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll v[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    ll answer = 0;
    cin >> n >> x;
    
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    
    for(int i = 1; i <= n; i++){
        if(v[i] + v[i - 1] > x){
            answer += ((v[i] + v[i - 1]) - x);
            v[i] -= ((v[i] + v[i - 1]) - x);
        }
    }
    
    cout << answer << endl;

    return 0;
}
