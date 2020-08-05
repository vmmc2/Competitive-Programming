#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    for(int i = 0; i + 1 < (int)s.size(); i++){
        if(s[i] == s[i + 1]){
            cout << i + 1 << " " << i + 2 << "\n";
            return 0;
        }
        if(s[i] == s[i + 2] && i + 2 < (int)s.size()){
            cout << i + 1 << " " << i + 3 << "\n";
            return 0;
        }
    }
    
    cout << "-1 -1" << "\n";
    
    return 0;
}
