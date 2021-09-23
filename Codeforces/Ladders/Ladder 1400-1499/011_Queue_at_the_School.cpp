#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<char> q(n), nq(n);

    for(auto &x : q){
        cin >> x;
    }

    for(int i = 1; i <= t; i++){
        int j = 0;
        while(j < n){
            if(j < n - 1 && q[j] == 'B' && q[j + 1] == 'G'){
                nq[j] = 'G';
                nq[j + 1] = 'B';
                j += 2;
            }else{
                nq[j] = q[j];
                j += 1;
            }
        }
        q = nq;
    }

    for(auto x : q){
        cout << x;
    }



    return 0;
}
