#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = (1e9 + 7);

int x[2000][2000], y[2000][2000], z[2000][2000];
int dp[2000][2000];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    char grid[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
        }
    }
    memset(x, 0, sizeof(dp));
    memset(y, 0, sizeof(dp));
    memset(z, 0, sizeof(dp));
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(i == 0 && j == 0) continue;
            if(grid[i][j] == '#') continue;
            if(j > 0) x[i][j] = (x[i][j - 1] + dp[i][j - 1]) % MOD;
            if(i > 0) y[i][j] = (y[i - 1][j] + dp[i - 1][j]) % MOD;
            if(i > 0 && j > 0) z[i][j] = (z[i - 1][j - 1] + dp[i - 1][j - 1]) % MOD;
            dp[i][j] = ((ll)x[i][j] + (ll)y[i][j] + (ll)z[i][j]) % MOD;
        }
    }
    cout << dp[h - 1][w - 1] << endl;
    return 0;
}
