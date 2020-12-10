#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sx, sy, gx, gy;
    double a, b, answer;
    cin >> sx >> sy >> gx >> gy;

    gy = -gy; //reflect

    a = (double)(sy - gy)/(double)(sx - gx);
    b = (double)(sy) - ((double)(sy - gy)/(double)(sx - gx)) * sx;

    answer = -b/a;
    printf("%.9lf\n", answer);

    return 0;
}
