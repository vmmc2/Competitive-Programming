#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    reverse(s.begin(), s.end());
    
    if(s[0] != 'm' && s[0] != 'r' && s[0] != 'e'){
        cout << "NO" << endl;
    }else if(s[(int)s.size() - 1] != 'd' && s[(int)s.size() - 1] != 'e'){
        cout << "NO" << endl;
    }else{
        int i = 0;
        int limit = s.size() - 1;
        while(){
            
        }
    }
    
    
    
    
    return 0;
}
