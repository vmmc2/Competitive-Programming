#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    string x;
    cin >> t;
    vector<string> unit = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector<string> init = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector<string> boring;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < (int)init.size(); j++){
            boring.push_back(init[j]);
        }
        for(int j = 0; j < (int)init.size(); j++){
            init[j] += unit[j];
        }
    }
    sort(boring.begin(), boring.end());
    for(int a = 0; a < t; a++){
        cin >> x;
        int answer = 0;
 
        for(auto y : boring){
            answer += (int)y.size();
            if(x == y) break;
        }
        cout << answer << "\n";
    }
    
 
    return 0;
}
