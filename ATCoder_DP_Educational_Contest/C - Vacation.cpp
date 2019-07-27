#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numdays;
    int dp[3][100100];
    
    cin >> numdays;
    vector <int> a(numdays), b(numdays), c(numdays);
    for(int i = 0; i < numdays; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[0][0] = a[0];
    dp[1][0] = b[0];
    dp[2][0] = c[0];
    for(int i = 1; i < numdays; i++){
        dp[0][i] = a[i] + max(dp[1][i - 1], dp[2][i - 1]);
        dp[1][i] = b[i] + max(dp[0][i - 1], dp[2][i - 1]);
        dp[2][i] = c[i] + max(dp[0][i - 1], dp[1][i - 1]);
    }
    cout << max(dp[0][numdays - 1], max(dp[1][numdays - 1], dp[2][numdays - 1])) << endl;
    
    return 0;
}
