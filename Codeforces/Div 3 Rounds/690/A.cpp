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
        vector<ll> v(n);
        vector<ll> answer;
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        int left = 0, right = n - 1;
        while(left <= right){
            if(left == right){
                answer.push_back(v[left]);
                left++;
                right--;
            }else{
                answer.push_back(v[left]);
                answer.push_back(v[right]);
                left++;
                right--;
            }
        }
        for(auto number : answer){
            cout << number << " ";
        }
        cout << "\n";
    }
 
 
    return 0;
}
