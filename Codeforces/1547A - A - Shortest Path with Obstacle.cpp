    #include <bits/stdc++.h>
    #include <sstream>
    #define pb push_back
    #define mp make_pair
    #define pii pair<int,int>
    #define vi vector<int>
     
    using namespace std;
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
     
    const ll p = 31;
    const ll MOD = 1000000007;
    const int dx[4] = {1, -1, 0,  0};
    const int dy[4] = {0,  0, 1, -1};
     
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
     
        int t;
        int xa, ya;
        int xb, yb;
        int xf, yf;
        cin >> t;
     
        for(int x = 0; x < t; x++){
            cin >> xa >> ya;
            cin >> xb >> yb;
            cin >> xf >> yf;
     
            int answer = 0;
            answer += (abs(xb - xa) + abs(yb - ya));
            int minx = min(xa, xb);
            int maxx = max(xa, xb);
            int miny = min(ya, yb);
            int maxy = max(ya, yb);
            if((xa == xb && xa == xf) && (miny <= yf && yf <= maxy)) answer += 2;
            if((ya == yb && ya == yf) && (minx <= xf && xf <= maxx)) answer += 2;
            cout << answer << endl;
        }
        return 0;
    }
