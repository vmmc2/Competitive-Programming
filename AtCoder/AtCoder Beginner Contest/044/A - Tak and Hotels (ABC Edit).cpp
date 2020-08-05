#include <bits/stdc++.h>
#define INF 0xffffffff
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, x, y;
    ll answer;
    
    cin >> n;
    cin >> k;
    cin >> x;
    cin >> y;
    
    if(n > k){
        answer = (x*k) + (y*(n - k));
    }else{
        answer = x*n;
    }
    
    cout << answer << endl;
    
    
    return 0;
}
