#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;

void backtrack(vector<ll> &data, vector<ll> &vecSum, int cursor, int n, ll sum, ll t){
    if(sum > t) return;
    if(cursor >= n && sum <= t){
        vecSum.push_back(sum);
        return;
    }
    backtrack(data, vecSum, cursor + 1, n, sum + data[cursor], t);
    backtrack(data, vecSum, cursor + 1, n, sum, t);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, t;
    cin >> n >> t;
    
    vector<ll> b;
    vector<ll> c;
    vector<ll> bSum;
    vector<ll> cSum;
    ll aux;
    for(int i = 0; i < n; i++){
        if(i < n/2){
            cin >> aux;
            b.push_back(aux);
        }else{
            cin >> aux;
            c.push_back(aux);
        }
    }
    int cursor = 0;
    ll sum = 0;
    backtrack(b, bSum, cursor, (int)b.size(), sum, t);
    backtrack(c, cSum, cursor, (int)c.size(), sum, t);
    sort(bSum.begin(), bSum.end());
    sort(cSum.begin(), cSum.end());
    ll answer = 0;
    for(int i = 0; i < (int)cSum.size(); i++){
        ll daVez1 = cSum[i], daVez2 = 0;
        ll target = t - daVez1;
        int low = 0, high = (int)bSum.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(bSum[mid] == target){
                daVez2 = bSum[mid];
                break;
            }else if(bSum[mid] < target){
                daVez2 = bSum[mid];
                low = mid + 1;
            }else if(bSum[mid] > target){
                high = mid - 1;
            }
        }
        answer = max(answer, daVez1 + daVez2);
    }
    
    cout << answer << endl;

    return 0;
}
