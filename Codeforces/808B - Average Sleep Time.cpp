#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define pb push_back
#define INF 99999999
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(register int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<ll> sum(n);
    for(register int i = 0; i < n; i++){
        if(i == 0) sum[i] = v[i];
        else{
            sum[i] = (v[i] + sum[i - 1])*1LL;
        }
    }
    int weeks = n - k + 1;
    double answer = 0;
    int p1 = -1;
    int p2 = k - 1;
    while(p2 < n){
        if(p1 == -1){
            answer += (double)sum[p2];
            p2++;
            p1++;
        }else{
            answer += (double)(sum[p2] - sum[p1]);
            p1++;
            p2++;
        }
    }
    double finale = (double)(answer/weeks);
    printf("%.10lf\n", finale);
    return 0;
}
