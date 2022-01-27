#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int curr = 0, len;
    string s;
    vector<string> v;
    string c = "", answer = "";
 
    cin >> s;
 
    len = (int)s.size();
 
    while(curr < len){
        if(curr <= len - 3){
            if(s[curr] == 'W' && s[curr + 1] == 'U' && s[curr + 2] == 'B'){
                if(c != "") v.push_back(c);
                c = "";
                curr += 3;
            }else{
                c += s[curr];
                curr += 1;
            }
        }else{
            c += s[curr];
            curr += 1;
        }
    }
    if(c != "") v.push_back(c);
 
    for(int i = 0; i < (int)v.size(); i++){
        if(i == (int)v.size() - 1){
            answer += v[i];
        }else{
            answer += v[i] + " ";
        }
    }
 
    cout << answer << endl;
 
    return 0;
}
