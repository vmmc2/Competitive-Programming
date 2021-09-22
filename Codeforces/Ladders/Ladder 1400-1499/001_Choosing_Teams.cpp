    #include <bits/stdc++.h>
    #include <sstream>
     
    using namespace std;
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
     
        int n, k;
        int answer = 0;
        cin >> n >> k;
     
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i] + k <= 5) answer++;
        }
     
        answer /= 3;
        cout << answer << endl;
     
        return 0;
    }
