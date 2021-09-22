#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    int answer = 0;
    while(n != 0){
        int digit = n % 10;
        if(digit == 4 || digit == 7) answer++;
        n = n/10;
    }
    //cout << "answer: " << answer << endl;

    if(answer == 4 || answer == 7) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
