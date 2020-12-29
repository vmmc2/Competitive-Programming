#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ll> students(n);
    vector<ll> teachers(m);
    vector<ll> prefixsum(n/2 + 1, 0);
    vector<ll> suffixsum(n/2 + 1, 0);

    for(int i = 0; i < n; i++){
        cin >> students[i];
    }
    sort(students.begin(), students.end());

    for(int i = 0; i < m; i++){
        cin >> teachers[i];
    }
    sort(teachers.begin(), teachers.end());

    //preparando prefixsum..
    for(int i = 0; i < (int)prefixsum.size(); i++){
        if(i == 0){
            prefixsum[i] = abs(students[2*i] - students[2*i + 1]);
        }else if(i > 0 && 2*i < n && 2*i + 1 < n){
            prefixsum[i] = prefixsum[i - 1] + abs(students[2*i] - students[2*i + 1]);
        }
    }
    //preparando sufixsum..
    for(int i = (int)suffixsum.size() - 1; i >= 0; i--){
        if(i == (int)suffixsum.size() - 1){
            suffixsum[i] = abs(students[2*i] - students[2*i - 1]);
        }else if(i < (int)suffixsum.size() - 1 && 2*i >= 0 && 2*i - 1 >= 0){
            suffixsum[i] = suffixsum[i + 1] + abs(students[2*i] - students[2*i - 1]);
        }
    }
    //bin search
    ll answer = 1e17;
    for(int i = 0; i < m; i++){
        int left = 0, right = n - 1;
        int index;
        if(teachers[i] <= students[0]){
            answer = min(answer, (students[0] - teachers[i]) + suffixsum[left/2 + 1]);
            continue;
        }else if(students[n - 1] <= teachers[i]){
            answer = min(answer, (teachers[i] - students[n - 1]) + prefixsum[(int)prefixsum.size() - 2]);
            continue;
        }
        while(left <= right){
            int mid = left + (right - left)/2;
            if(students[mid] <= teachers[i]){
                index = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        if(index % 2 == 0){
            int dale, dele;
            if(index/2 - 1 < 0){
                dale = 0;
            }else{
                dale = prefixsum[index/2 - 1];
            }
            if(index/2 + 1 >= (int)suffixsum.size()){
                dele = 0;
            }else{
                dele = suffixsum[index/2 + 1];
            }
            answer = min(answer, abs(teachers[i] - students[index]) + dale + dele);
        }else{
            int dale, dele;
            if(index/2 < 0){
                dale = 0;
            }else{
                dale = prefixsum[index/2];
            }
            if(index/2 + 2 >= (int)suffixsum.size()){
                dele = 0;
            }else{
                dele = suffixsum[index/2 + 2];
            }
            answer = min(answer, abs(students[index + 1] - teachers[i]) + dale + dele);
        }  
    }

    cout << answer << "\n";
    return 0;
}
