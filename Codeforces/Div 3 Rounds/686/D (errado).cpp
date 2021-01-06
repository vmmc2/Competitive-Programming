#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<ull> trialDivision(ull n){
    vector<ull> factors;
    for(ull d = 2; d * d <= n; d++){
        while(n % d == 0){
            factors.push_back(d);
            n = n/d;
        }
    }
    if(n > 1) factors.push_back(n);
    return factors;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    ull n;

    cin >> t;
    for(int a = 0; a < t; a++){
        cin >> n;
        vector<ull> factors = trialDivision(n);
        
        /*for(auto x : factors){
            cout << x << " ";
        }*/
        vector<ull> answers;
        if((int)factors.size() == 1){
            cout << "1" << "\n";
            cout << factors[0] << "\n";
        }else{
            bool found = true;
            int left = 0, right = 1;
            ull current, next;
            while(right < (int)factors.size()){
                current = factors[left];
                next = factors[right];
                if(next % current == 0){
                    answers.push_back(next);
                }else{
                    right++;
                    ull finale = current * next;
                    while(right < (int)factors.size()){
                        finale = finale * factors[right];
                        right++;
                    }
                    answers.push_back(finale);
                }
                left++;
                right++;
            }
            if(found == false){
                cout << "1" << "\n";
                cout << n << "\n";
            }else{
                cout << (int)answers.size() << "\n";
                for(auto x : answers){
                    cout << x << " ";
                }
                cout << "\n";
            }
        }


    }

    return 0;
}
