#include <bits/stdc++.h>

using namespace std;

int main(){
    string name;
    int i = 1;
    while(1){
        getline(cin, name);
        if(name == "*") break;
        else{
            if(name == "Hajj"){
                printf("Case %d: Hajj-e-Akbar\n", i);
            }
            else if(name == "Umrah"){
                printf("Case %d: Hajj-e-Asghar\n", i);
            }
        }
    i++;    
    }
    return 0;
}
