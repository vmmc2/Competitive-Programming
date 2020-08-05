#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::string s;
    std::vector<char> v;
    
    std::cin >> s;
    
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '0'){
            v.push_back('0');
        }else if(s[i] == '1'){
            v.push_back('1');
        }else if(s[i] == 'B'){
            if((int)v.size() == 0) continue;
            else{
                v.pop_back();
            }
        }
    }
    
    for(auto element : v){
        std::cout << element;
    }
    
    
    return 0;
}
