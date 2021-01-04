#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    for(int a = 0; a < t; a++){
        int n;
        cin >> n;

        vector<ll> v(n);
        vector<ll> freq(n + 1, 0);
        ll answer = 0;

        for(int i = 0; i < n; i++){
            cin >> v[i];
            freq[v[i]]++;
        }
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            sum += ((freq[i]) * (freq[i] - 1) * (freq[i] - 2))/6;
        }
        for(int i = 1; i <= n - 2; i++){
            sum += (freq[i]*(freq[i] - 1)/2) * freq[i + 2];
        }
        for(int i = 1; i <= n - 1; i++){
             sum += (freq[i]*(freq[i] - 1)/2) * freq[i + 1];
        }
        for(int i = 1; i <= n - 2; i++){
            sum += freq[i] * (freq[i + 2] * (freq[i + 2] - 1))/2;
        }
        for(int i = 1; i <= n - 1; i++){
            sum += freq[i] * (freq[i + 1] * (freq[i + 1] - 1))/2;
        }
        for(int i = 1; i <= n - 2; i++){
            sum += freq[i] * freq[i + 1] * freq[i + 2];
        }
        cout << sum << "\n";
    }


    return 0;
}
