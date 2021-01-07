#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
bool allEqual(vector<int> &v){
    int pivot = v[0];
    int ok = true;
    for(auto x : v){
        if(x != pivot){
            ok = false;
            break;
        }
    }
    return ok;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
 
    for(int a = 0; a < t; a++){
        int n;
        cin >> n;
        vector<int> v(n);
 
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
 
        if(allEqual(v)){
            cout << "-1" << "\n";
        }else{
            int answer = -1;
            int mx = -1e3;
            for(int i = 0; i < (int)v.size(); i++){
                mx = max(mx, v[i]);
            }
            for(int i = 0; i < (int)v.size(); i++){
                if(mx == v[i]){
                    if(i - 1 >= 0 && v[i - 1] < v[i]){
                        answer = i + 1;
                        break;
                    }
                    if(i + 1 < (int)v.size() && v[i] > v[i + 1]){
                        answer = i + 1;
                        break;
                    }
                }
            }
            cout << answer << "\n";
        }
    }
 
 
    return 0;
}
