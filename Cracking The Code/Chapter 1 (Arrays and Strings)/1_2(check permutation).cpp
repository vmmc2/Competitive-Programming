#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

bool check_permutation(string s1, string s2){
    int hashtable1[128] = {0};
    int hashtable2[128] = {0};
    for(int i = 0; i < (int)s1.length(); i++){
        hashtable1[(int)s1[i]]++;
    }
    for(int i = 0; i < (int)s2.length(); i++){
        hashtable2[(int)s2[i]]++;
    }
    for(int i = 0; i < 128; i++){
        if(hashtable1[i] != hashtable2[i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s1 = "aaae";
    string s2 = "aaaa";
    
    if((int)s1.length() != (int)s2.length()){
        cout << "No, s2 is not a permutation of s1." << "\n";
        return 0;
    }
    
    if(check_permutation(s1, s2)){
        cout << "Yes, s2 is a permutation of s1." << "\n";
    }else{
        cout << "No, s2 is not a permutation of s1." << "\n";
    }
    return 0;
}
