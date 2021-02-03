#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    int a, b;
    cin >> t;
 
    for(int x = 0; x < t; x++){
        cin >> a >> b;
        if(a == b){
            cout << "0" << "\n";
        }else{
            int diff = abs(b - a);
            int count = 0;
            count += floor(diff/10);
            if(diff % 10 != 0) count++;
            cout << count << "\n";
        }
    }
 
 
 
    return 0;
}
