#include <bits/stdc++.h>

using namespace std;

bool hasUnique(string s1){
    int hashtable[128] = {0};
    int tam = (int)s1.length();
    for(int i = 0; i < tam; i++){
        hashtable[(int)s1[i]]++;
    }
    for(int i = 0; i < 128; i++){
        if(hashtable[i] > 1) return false;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s = "abcda";
    if(hasUnique(s)){
        cout << "This string has all unique characters" << "\n";
    }else{
        cout << "This string has not unique characters" << "\n";
    }
    
    
    return 0;
}
