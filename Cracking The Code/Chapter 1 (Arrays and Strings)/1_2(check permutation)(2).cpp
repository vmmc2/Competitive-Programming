#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

bool check_permutation(string s1, string s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1 != s2){
        return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s1 = "eaaa";
    string s2 = "aeaa";
    
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
