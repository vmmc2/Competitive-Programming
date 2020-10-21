#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    char c;
    cin >> c;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
    
    return 0;
}
