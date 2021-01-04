#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t, lixeira;
    cin >> t;
 
    for(int a = 0; a < t; a++){
        string s;
        cin >> lixeira;
        cin >> s;
 
        int n = (int)s.length();
        bool canTransform = false;
 
        if(s == "2020"){ // 0 movimentos...
            canTransform = true;
        }else{
            if(s.substr(0, 4) == "2020"){
                canTransform = true;
            }else if(s.substr(n - 4 ,4) == "2020"){
                canTransform = true;
            }
 
            if(s[0] == '2' && s.substr(n - 3, 3) == "020"){
                canTransform = true;
            }else if(s.substr(0, 3) == "202" && s[n - 1] == '0'){
                canTransform = true;
            }
 
            if(s.substr(0, 2) == "20" && s.substr(n - 2, 2) == "20"){
                canTransform = true;
            }
        }
 
        if(canTransform) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
 
    return 0;
}
