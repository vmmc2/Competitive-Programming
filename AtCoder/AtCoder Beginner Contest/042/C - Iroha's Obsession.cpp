#include <bits/stdc++.h>

using namespace std;

bool check(int number, vector<int> &v){
    while(number != 0){
        int digit = number % 10;
        if(v[digit] == 1) return false;
        number = number/10;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int amount, k, answer;
    cin >> amount >> k;
    
    vector<int> v(9, 0);
    for(int i = 0; i < k; i++){
        int number;
        cin >> number;
        v[number] = 1;
    }
    for(int a = amount; ; a++){
        if(check(a, v) == true){
            answer = a;
            break;
        }
    }
    cout << answer << "\n";
    
    return 0;
}
