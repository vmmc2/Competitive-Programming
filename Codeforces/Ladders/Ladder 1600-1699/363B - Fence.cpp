#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, k, answer = 2e8;
    int check = 1;
    cin >> n >> k;
 
 
    vector<int> v(n);
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        if(i == 0) dp[i] = v[i];
        else dp[i] = dp[i - 1] + v[i];
    }
 
    /*for(auto x : dp){
        cout << x << " ";
    }
    cout << endl << endl;*/
 
    int left = 0, right = k - 1;
    while(right < n){
        //cout << "left: " << left << " --- right: " << right << endl;
        if(left == 0){
            if (dp[right] < answer){
                answer = dp[right];
                check = left + 1;
            }
        }else{  
            if(dp[right] - dp[left - 1] < answer){
                answer = dp[right] - dp[left - 1];
                //cout << answer << endl;
                check = left + 1;
            }
        }
        right++, left++;
    }
    cout << check << endl;
 
    return 0;
}
