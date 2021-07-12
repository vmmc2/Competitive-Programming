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
        cin >> t;
     
        for(int x = 0; x < t; x++){
            int k, n, m;
            cin >> k >> n >> m;
     
            vector<int> monocarp(n);
            vector<int> polycarp(m);
            vector<int> answer;
            for(int i = 0; i < (int)monocarp.size(); i++){
                cin >> monocarp[i];
            }
            for(int i = 0; i < (int)polycarp.size(); i++){
                cin >> polycarp[i];
            }
     
            int leftmc = 0, leftpc = 0;
            bool DeuRuim = false;
            bool monocarpTravou = false, polycarpTravou = false;
            while(leftmc < (int)monocarp.size() || leftpc < (int)polycarp.size()){
                if(leftmc < (int)monocarp.size()){
                    if(monocarp[leftmc] == 0){
                        answer.push_back(monocarp[leftmc]);
                        k++;
                        leftmc++;
                        continue;
                    }else if(monocarp[leftmc] > 0 && monocarp[leftmc] <= k){
                        answer.push_back(monocarp[leftmc]);
                        leftmc++;
                        monocarpTravou = false;
                    }else{
                        monocarpTravou = true;
                    }
                }else{
                    monocarpTravou = true;
                }
                if(leftpc < (int)polycarp.size()){
                    if(polycarp[leftpc] == 0){
                        answer.push_back(polycarp[leftpc]);
                        k++;
                        leftpc++;
                        continue;
                    }else if(polycarp[leftpc] > 0 && polycarp[leftpc] <= k){
                        answer.push_back(polycarp[leftpc]);
                        leftpc++;
                        polycarpTravou = false;
                    }else{
                        polycarpTravou = true;
                    }
                }else{
                    polycarpTravou = true;
                }
                if(monocarpTravou == true && polycarpTravou == true){
                    DeuRuim = true;
                    break;
                }
            }
            if(DeuRuim == true){
                cout << "-1" << endl;
            }else{
                for(auto x : answer){
                    cout << x << " ";
                }
                cout << endl;
            }
     
        }
        return 0;
    }
