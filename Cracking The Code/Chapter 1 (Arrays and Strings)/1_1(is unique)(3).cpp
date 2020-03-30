#include <bits/stdc++.h>

using namespace std;

//I am considering that the string is composed of only ASCII characters
//And I am not considering the ASCII extended table. I am considering the
//standard one, which has 128 characters.
bool isUniqueChar(string s1){
    bool hasSeen[128] = {false};
    if(s1.length() > 128) return false;
    for(int i = 0; i < s1.length(); i++){
        if(hasSeen[s1[i]] == false){
            hasSeen[s1[i]] = true;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s1 = "aeiou";
    
    if(isUniqueChar(s1)){
        cout << "The string has only unique characters." << "\n";
    }else{
        cout << "The string does not have unique characters." << "\n";
    }
    
    return 0;
}
