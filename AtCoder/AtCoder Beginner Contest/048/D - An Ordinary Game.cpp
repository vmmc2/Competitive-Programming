#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int x = 0, y = 0;
    if((int)s.size() % 2 == 0){
        x = 1;    
    }
    if(s[0] == s[(int)s.size() - 1]){
        y = 1;
    }
    if(x ^ y){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
    
    return 0;
}
