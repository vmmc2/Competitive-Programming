#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool alreadyAnswer(ll n, ll s){
    ll digitSum = 0;
    while(n != 0){
        digitSum += (n % 10);
        n = n/10;
    }
    if(digitSum <= s) return true;
    else return false;
}

ll pot10[19];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(ll i = 0, current = 1; i < 19; i++, current *= 10){
        pot10[i] = current;
    }

    int t;
    ll n, s;

    cin >> t;
    for(int caso = 0; caso < t; caso++){
        cin >> n >> s;
        ll answer = 0;
        
        if(alreadyAnswer(n, s) == true){
            cout << "0" << "\n";
        }else{
            bool foundAnswer = false;
            int exponent = 1;
            while(foundAnswer == false){
                ll digit = (n % pot10[exponent])/pot10[exponent - 1];
                ll valueToSum = (10 - digit)*(pot10[exponent - 1]);
                answer += valueToSum;
                n += valueToSum;
                if(alreadyAnswer(n, s) == true) foundAnswer = true;
                exponent++;
            }
            cout << answer << "\n";
        }
    }


    return 0;
}
