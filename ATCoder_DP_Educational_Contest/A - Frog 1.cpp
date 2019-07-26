#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define MAX 100100

using namespace std;

int main(){
    int n;
    int aux;
    vector<int> p;
    int dp[MAX];
    p.pb(0);
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        p.pb(aux);
    }
    memset(dp, 0, sizeof dp);
    dp[2] = abs(p[1] - p[2]);
    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i - 2] + abs(p[i - 2] - p[i]), dp[i - 1] + abs(p[i - 1] - p[i]));
    }
    printf("%d\n", dp[n]);
    
    
    return 0;
}
