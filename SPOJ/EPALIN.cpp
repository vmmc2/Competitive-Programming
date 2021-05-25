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

const ll p = 59;
const ll MOD = 1000000007;
const int dx[4] = {1, -1, 0,  0};
const int dy[4] = {0,  0, 1, -1};

void rabin_karp(string s, vector<ll> &preffix_hash, vector<ll> &suffix_hash, map<char,int> table, vector<ll> &pp){
    ll power = 1;
    pp[0] = 1;
    int rtl = s.size() - 1;
    preffix_hash[0] = (table[s[0]] * power) % MOD;
    suffix_hash[rtl] = (table[s[rtl]] * power) % MOD;
    rtl--;

    for(int i = 1; i < (int)s.size(); i++, rtl--){
        pp[i] = (pp[i - 1] * p) % MOD;
        preffix_hash[i] = (preffix_hash[i - 1] + table[s[i]]*pp[i]) % MOD;
        suffix_hash[rtl] = (suffix_hash[rtl + 1] + table[s[rtl]]*pp[i]) % MOD;
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    map<char,int> table;
    int i = 1;
    for(char ch = 'a', i = 1; ch <= 'z'; ch++, i++){
        table[ch] = i;
    }   
    for(char ch = 'A', i = 27; ch <= 'Z'; ch++, i++){
        table[ch] = i;
    }


    while(getline(cin, s)){
        vector<ll> preffix_hash(s.size(), 0);
        vector<ll> suffix_hash(s.size(), 0);
        vector<ll> power(s.size(), 0);

        rabin_karp(s, preffix_hash, suffix_hash, table, power);


        int leftp = 0, rightp = s.size() - 1;
        int lefts = s.size() - 1, rights = 0;
        bool foundAnswer = false;

        while(leftp < rightp){
            if(leftp == 0){
                if(preffix_hash[rightp] == suffix_hash[rights]){
                    foundAnswer = true;
                    break;
                }
            }else{
                if((preffix_hash[rightp] - preffix_hash[leftp - 1] + MOD) % MOD == ((suffix_hash[rights] * power[leftp]) % MOD)){
                    foundAnswer = true;
                    break;
                }
            }
            leftp++;
            rights++;
        }
        if(foundAnswer == true){
            string aux = s.substr(0, leftp);
            reverse(aux.begin(), aux.end());
            string answer = s + aux;
            cout << answer << endl;
        }else{
            string aux = s.substr(0, s.size() - 1);
            reverse(aux.begin(), aux.end());
            string answer = s + aux;
            cout << answer << endl;
        }
    }
    
    return 0;
}
