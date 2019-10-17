    #include <bits/stdc++.h>
    #include <sstream>
    #include <cmath>
    #define pb push_back
    #define INF 99999999
     
    using namespace std;
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n;
        cin >> n;
        vector<int> v(n);
        map<int,int> b;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            b[v[i]]++;
            ans = max(ans, b[v[i]]);
        }
        cout << (n - ans) << "\n";
        return 0;
    }
