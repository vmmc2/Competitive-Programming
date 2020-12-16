#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    if((int)s.size() == 1){
        if(stoi(s) % 8 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else if((int)s.size() == 2){
        if(stoi(s) % 8 == 0){
            cout << "Yes" << endl;
        }else{
            swap(s[0], s[1]);
            if(stoi(s) % 8 == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }else{
        int n = (int)s.size();
        vector<int> freq(10, 0);
        for(int i = 0; i < n; i++){
            freq[s[i] - '0']++;
        }
        bool found = true;
        for(int i = 112; i < 1000; i += 8){
            found = true;
            auto v = freq;
            string aux = to_string(i);
            for(auto x : aux) v[x - '0']--;
            for(int j = 0; j < v.size(); j++){
                if(v[j] < 0) found = false;
            }
            if(found == true) break;
        }
        if(found == true) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
