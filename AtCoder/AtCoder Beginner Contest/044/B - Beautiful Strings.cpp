#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> freq(26, 0);
    bool beautiful = true;
    
    string s;
    cin >> s;
    
    for(int i = 0; i < (int)s.size(); i++){
        freq[s[i] - 'a']++;
    }
    
    for(int i = 0; i < 26; i++){
        if(freq[i] % 2 != 0) beautiful = false;
    }
    
    if(beautiful){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    
    
    return 0;
}
