    #include <bits/stdc++.h>
    #include <sstream>
    #define pb push_back
    #define mp make_pair
    #define pii pair<int,int>
    #define vi vector<int>
     
    using namespace std;
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
     
    const ll p = 31;
    const ll MOD = 1000000007;
    const int dx[4] = {1, -1, 0,  0};
    const int dy[4] = {0,  0, 1, -1};
     
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
     
        int t;
        string s;
        cin >> t;
     
        for(int x = 0; x < t; x++){
            cin >> s;
            bool ok = true;
            vector<int> freq(26, 0);
     
            for(int i = 0; i < (int)s.size(); i++){
                freq[s[i] - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                if(freq[i] > 1 || (freq[i] != 0 && i + 1 > (int)s.size())){
                    ok = false;
                    break;
                }
            }
            if(ok == false){
                cout << "NO" << endl;
                continue;
            }
            //tem que achar a posicao de 'a'.
            int aindex;
            vector<int> ind(26, 0);
            for(int i = 0; i < (int)s.size(); i++){
                if(s[i] == 'a'){
                    aindex = i;
                    break;
                }
            }
            int left = aindex - 1, right = aindex + 1;
            bool deuMtruim = false;
            char next = 'b';
            while(left >= 0 || right < (int)s.size()){
                bool found = false;
                if(left >= 0){
                    if(s[left] == next){
                        next = (char)((int)next + 1);
                        found = true;
                        left--;
                        continue;
                    }
                }
                if(right < s.size()){
                    if(s[right] == next){
                        next = (char)((int)next + 1);
                        found = true;
                        right++;
                        continue;
                    }
                }
                if(found == false){
                    cout << "NO" << endl;
                    deuMtruim = true;
                    break;
                }
            }
            if(deuMtruim == false) cout << "YES" << endl;
     
        }
        return 0;
    }
