#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    if(a == b && b == c && a == c){
        cout << "1" << endl;
    }else if(a != b && b != c && a != c){
        cout << "3" << endl;
    }else{
        cout << "2" << endl;
    }
    
    return 0;
}
