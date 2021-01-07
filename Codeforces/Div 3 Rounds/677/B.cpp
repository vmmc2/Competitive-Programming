#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    for(int a = 0; a < t; a++){
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        int left = 0, right = n - 1;
        while(left < n && v[left] != 1){
            left++;
        }
        while(right >= 0 && v[right] != 1){
            right--;
        }
        int cursor = left + 1;
        int answer = 0;
        while(cursor < right){
            if(v[cursor] == 0) answer++;
            cursor++;
        }
        cout << answer << "\n";
    }


    return 0;
}
