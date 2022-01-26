#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main(){
    long long n, k;
    long long answer;
    cin >> n >> k;

    if(n % 2 == 0){ // n eh par
        if(k <= n/2){ // foco nos impares
            answer = 1LL + (long long)((k - 1)*2);
        }else{ // foco nos pares
            k = k - n/2;
            answer = (long long)(2) + (long long)((k - 1)*2);
        }
    }else{ // impar
        if(k <= n/2 + 1){ // foco nos impares
            answer = 1LL + (long long)((k - 1)*2);
        }else{ // foco nos pares
            k = k - (n/2 + 1);
            answer = (long long)(2) + (long long)((k - 1)*2);
        }
    }
    cout << answer << endl;

    return 0;
}
