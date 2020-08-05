#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    int begin = -1;
    int end = -1;
    
    cin >> s;
    
    if((int)s.size() == 1){
        cout << "-1 -1" << "\n";
        return 0;
    }
    
    
    for(int substringlen = 2; substringlen <= (int)s.size(); substringlen++){
        vector<int> freq(26, 0);
        for(int i = 0; i < substringlen; i++){
            freq[s[i] - 'a']++;
        }
        int left = 0;
        int right = substringlen - 1;
        for(int i = 0; i < 26; i++){
            if(freq[i] > substringlen/2){
                begin = left;
                end = right;
            }
        }
        if(begin != -1 && end != -1){
            break;
        }
        for(int i = left, j = right + 1; i <= (int)s.size() - substringlen + 1; i++, j++){
            freq[s[i] - 'a']--;
            freq[s[j] - 'a']++;
            for(int k = 0; k < 26; k++){
                if(freq[k] > substringlen/2){
                    begin = i + 1;
                    end = j;
                } 
            }
            if(begin != -1 && end != -1){
                break;
            }
        }
        if(begin != -1 && end != -1){
            break;
        }
    }
    if(begin == -1 && end == -1){
        cout << "-1 -1" << "\n";
        return 0;
    }
    
    cout << begin + 1 << " " << end + 1 << "\n";
    
    return 0;
}
