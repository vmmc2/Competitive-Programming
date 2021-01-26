#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    int n, x;
    cin >> t;
 
    for(int a = 0; a < t; a++){
        cin >> n >> x;
        vector<int> v(1100);
        v[1] = 2;
        if(n <= 2){
            cout << "1" << "\n";
        }else{
            for(int i = 2; i < 1100; i++){
                v[i] += v[i - 1] + x;
                if(v[i] >= n){
                    cout << i << "\n";
                    break;
                }
            }
        }
    }
 
 
    return 0;
}
