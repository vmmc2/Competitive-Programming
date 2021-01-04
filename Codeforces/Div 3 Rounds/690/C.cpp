#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;
 
int digitSum(string i){
    int answer = 0;
    for(auto ch : i){
        answer += ((int)ch - (int)'0');
    }
    return answer;
}
 
bool check(string s){
    unordered_set<char> freq;
    
    for(auto ch : s){
        if(freq.find(ch) == freq.end()){
            freq.insert(ch);
        }else{
            return false;
        }
    }
    return true;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t, number;
    cin >> t;
 
    for(int a = 0; a < t; a++){
        cin >> number;
 
        if(to_string(number).length() == 1){
            cout << number << "\n";
        }else{
            if(number > 45) cout << "-1" << "\n";
            else{
                string suffix;
                int left = 1;
                int right;
                if(number >= 10 && number <= 17){
                    suffix = "9";
                    right = 8;
                }
                else if(number >= 18 && number <= 24){
                    //cout << "entrei" << "\n";
                    suffix = "89";
                    right = 7;
                }
                else if(number >= 25 && number <= 30){
                    suffix = "789";
                    right = 6;
                }
                else if(number >= 31 && number <= 35){
                    suffix = "6789";
                    right = 5;
                }
                else if(number >= 36 && number <= 39){
                    suffix = "56789";
                    right = 4;
                }
                else if(number >= 40 && number <= 42){
                    suffix = "456789";
                    right = 3;
                }
                else if(number >= 43 && number <= 44){
                    suffix = "3456789";
                    right = 2;
                }
                else if(number == 45){
                    suffix = "23456789";
                    right = 1;
                }
                for(int i = left; i <= right; i++){
                    if(digitSum(to_string(i) + suffix) == number && check(to_string(i) + suffix)){
                        cout << to_string(i) + suffix << "\n";
                    }
                }
            }
        }
    }
 
    return 0;
}
