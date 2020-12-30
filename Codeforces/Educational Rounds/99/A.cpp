#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    string num;
    cin >> t;
 
    for(int i = 0; i < t; i++){
        cin >> num;
        cout << (int)num.size() << "\n";
    }
 
    return 0;
}
