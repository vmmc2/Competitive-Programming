#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    //Tratando dos corner cases antes.
    if((int)s.size() == 1){
        if(stoi(s) % 8 == 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        return 0;
    }else if((int)s.size() == 2){
        if(stoi(s) % 8 == 0){
            cout << "Yes" << endl;
        }
        swap(s[0], s[1]);
        if(stoi(s) % 8 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }else{
        vector<int> freq(10, 0);
        for(auto x : s) freq[x - '0']++;

        for(int i = 112; i < 1000; i += 8){
            auto vs = freq;
            string curr = to_string(i);
            for(auto x : curr){
                vs[x - '0']--;
            }
            bool ok = true;
            for(auto s : vs){
                if(s < 0) ok = false;
            }
            if(ok){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
