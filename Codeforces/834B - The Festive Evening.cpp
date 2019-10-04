#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    string str;
    cin >> n >> k;
    cin >> str;
    set<int> to_usando;
    map<char,int> registro;
    int deubom = 1;
    for(int i = 0; i < (int)str.size(); i++){
        registro[str[i]]++;
    }
    for(int i = 0; i < (int)str.size(); i++){
        if(to_usando.find(str[i]) == to_usando.end()){//se 
            to_usando.insert(str[i]);
            registro[str[i]]--;
            k--;
            if(k < 0){
                deubom = 0;
                break;
            }
            if(registro[str[i]] == 0){
                k++;
            }
        }else{
            registro[str[i]]--;
            if(registro[str[i]] == 0){
                k++;
            }
        }
        if(k < 0){
            deubom = 0;
            break;
        }
    }
    if(deubom == 0){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
    }
    return 0;
}
