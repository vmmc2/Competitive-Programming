    #include <bits/stdc++.h>
    #include <sstream>
     
    using namespace std;
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
     
        string name1, name2, name3;
        vector<int> freq(26, 0);
        vector<int> newfreq(26, 0);
     
        cin >> name1;
        cin >> name2;
        cin >> name3;
     
        for(auto x : name1){
            freq[x - 'A']++;
        }
        for(auto x : name2){
            freq[x - 'A']++;
        }
        for(auto x : name3){
            newfreq[x - 'A']++;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] != newfreq[i]){
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
     
        return 0;
    }
