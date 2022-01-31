#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    vector<ll> dp(n, 0);
    ll max1 = -1e10, left1 = -1, right1 = -1;
    ll max2 = -1e10, left2 = -1, right2 = -1;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i == 0) dp[i] = v[i];
        else dp[i] = dp[i - 1] + v[i];
    }
    int curl = 0, curr = k - 1;
    while(curr < n){
        if(curl == 0){
            if(dp[curr] > max1){
                max1 = dp[curr];
                left1 = curl;
                right1 = curr;
            }
        }else{
            if(dp[curr] - dp[curl - 1] > max1){
                max1 = dp[curr] - dp[curl - 1];
                left1 = curl;
                right1 = curr;
            }
        }
        curl++, curr++;
    }
    curl = 0, curr = k - 1;


    //cout << left1 << " " << right1 << endl;
    //cout << endl << endl;

    while(curr < n){
        //cout << "curl: " << curl << " ----- right2: " << curr << endl;
        if((left1 == curl && right1 == curr) || (curl <= left1 && curr >= left1) || (curl <= right1 && curr >= right1)){
            //cout << "entrei" <<  endl;
            curl = right1 + 1, curr += right1 + k - 1;
            continue;
        }
        if(curl == 0){
            if(dp[curr] > max2){
                max2 = dp[curr];
                left2 = curl;
                right2 = curr;
            }
        }else{
            if(dp[curr] - dp[curl - 1] > max2){
                max2 = dp[curr] - dp[curl - 1];
                left2 = curl;
                right2 = curr;
            }
        }
        curl++, curr++;
    }
    //cout << endl << endl;


    cout << min(left1 + 1, left2 + 1) << " " << max(left1 + 1, left2 + 1) << endl;
 
    return 0;
}
