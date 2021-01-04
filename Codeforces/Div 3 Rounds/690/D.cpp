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
    cin >> t;

    for(int a = 0; a < t; a++){
        int n;
        cin >> n;

        ll sum = 0;
        vector<ll> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            sum += v[i];
        }

        for(int i = n; i >= 1; i--){
            if(sum % i == 0){
                ll neededSum = sum/i;
                bool ok = true;
                ll currentSum = 0;
                for(int j = 0; j < n; j++){
                    currentSum += v[j];
                    if(currentSum > neededSum){
                        ok = false;
                        break;
                    }else if(currentSum == neededSum){
                        currentSum = 0;
                    }
                }
                if(ok == true){
                    cout << n - i << "\n";
                    break;
                }
            }
        }
    }


    return 0;
}
