#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t, n;
    cin >> t;
 
    for(int a = 0; a < t; a++){
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            v[i] = i + 1;
        }
        if(n % 2 == 0){
            for(int i = 0; i < n - 1; i += 2){
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }else{
            for(int i = 0; i < n; ){
                if(i == n - 3){
                    int temp1 = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = temp1;
 
                    int temp2 = v[i + 1];
                    v[i + 1] = v[i + 2];
                    v[i + 2] = temp2;
 
                    i += 3;
                }else{
                    int temp = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = temp;
                    i += 2;
                }
            }
        }
        for(auto el : v){
            cout << el << " ";
        }
        cout << "\n";
    }
 
    return 0;
}
