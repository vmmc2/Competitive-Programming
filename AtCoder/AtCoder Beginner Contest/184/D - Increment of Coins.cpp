#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double dp[101][101][101];

double funct(int a, int b, int c){
    if(dp[a][b][c]) return dp[a][b][c];
    if(a == 100 || b == 100 || c == 100) return 0;

    double ans = 0;
    ans += (funct(a + 1, b, c) + 1)*a/(a + b + c);
    ans += (funct(a, b + 1, c) + 1)*b/(a + b + c);
    ans += (funct(a, b, c + 1) + 1)*c/(a + b + c);
    dp[a][b][c] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    printf("%.9lf\n", funct(a, b, c));

    return 0;
}
